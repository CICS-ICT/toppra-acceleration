#include <toppra/solver/seidel-parallel-hls.hpp>

void solve_lp2d_parallel_hls(const toppra::solver::RowVector2 v, 
    const toppra::solver::MatrixX3& A, 
    const toppra::solver::Vector2& low, 
    const toppra::solver::Vector2& high, 
    toppra::solver::seidel::LpSol& sol)
{
  toppra::solver::MatrixX2 A_1d = toppra::solver::MatrixX2::Zero(A.rows() + 4, 2);
  assert(A_1d.rows() == A.rows()+4);
  sol.feasible = false;

  // number of working set recomputation
  unsigned int nrows = A.rows() - 2;
  toppra::solver::Vector2 cur_optvar = sol.optvar;

  // absolute bounds used in solving the 1 dimensional
  // optimization sub-problems. These bounds needs to be very
  // large, so that they are never active at the optimization
  // solution of these 1D subproblem..


  // handle fixed bounds (low, high). The following convention is
  // adhered to: fixed bounds are assigned the numbers: -1, -2, -3,
  // -4 according to the following order: low[0], high[0], low[1],
  // high[1].
  // for (int i = 0; i < 2; ++i) {
  for (int i = 0; i < 2; ++i) {
    if (low[i] > high[i]) {
      // If the difference between low and high is sufficiently small, then
      // return infeasible.
      if (   low[i] - high[i] > std::max(std::abs(low[i]),std::abs(high[i]))* toppra::solver::seidel::REL_TOLERANCE
          || low[i] == toppra::solver::seidel::infi
          || high[i] == -toppra::solver::seidel::infi) {
        printf("[WARN] -> incoherent bounds. high - low = (%f, %f)", (high - low)[0], (high - low)[1]);
        return;
      }
      // Otherwise, assume variable i is static. Thus we are left with a 1D LP.
      int j = 1-i;
      sol.optvar[i] = (low[i]+high[i])/2;
      A_1d.topRows(nrows) << A.col(j), A.col(2) + sol.optvar[i] * A.col(i);
      A_1d.middleRows<2>(nrows) << -1,   low[j],
                                    1, -high[j];

      toppra::solver::seidel::LpSol1d sol_1d = toppra::solver::seidel::solve_lp1d({ v[j], 0. }, A_1d.topRows(nrows+2));
      if (!sol_1d.feasible) {
        printf("[WARN] -> infeasible 1");
        return;
      }
      sol.optvar[j] = sol_1d.optvar;
      sol.feasible = true;
      sol.optval = v * sol.optvar;
    }

    cur_optvar[i]   = v[i] > 0 ? high[i] : low[i];
  }

  // pre-process the inequalities, remove those that are redundant

  // handle other constraints in a, b, c
  for (int i = 0; i < nrows; ++i) {
    // if current optimal variable satisfies the i-th constraint, continue
    if (toppra::solver::seidel::value(A.row(i), cur_optvar) < toppra::solver::seidel::ABS_TOLERANCE)
      continue;
    // otherwise, project all constraints on the line defined by (a[i], b[i], c[i])
    // project the origin (0, 0) onto the new constraint
    // let ax + by + c=0 b the new constraint
    // let zero_prj be the projected point, one has
    //     zero_prj =  1 / (a^2 + b^2) [a  -b] [-c]
    //                                 [b   a] [ 0]
    // this can be derived using perpendicularity
    toppra::solver::Vector2 zero_prj (A.row(i).head<2>());
    zero_prj *= - A(i,2) / zero_prj.squaredNorm();

    // Let x = zero_prj + d_tan * t
    // where t is the variable of the future 1D LP.
    toppra::solver::Vector2 d_tan { -A(i,1), A(i,0) }; // vector parallel to the line
    toppra::solver::Vector2 v_1d { v * d_tan, 0 };

    // Size of the 1D LP: 4 + k
    // Compute the constraint parameters of the 1D LP corresponding to the
    // linear constraints.
    for (int j = 0; j < i; ++j)
      toppra::solver::seidel::internal::project_linear_constraint(A.row(j),
              d_tan, zero_prj, A_1d.row(j));
    //A_1d.topRows(k) << A.topRows(k) * d_tan, value(A.topRows(k), zero_prj);
    // Compute the constraint parameters of the 1D LP corresponding to the
    // 4 bound constraints.
    // handle low <= x
    toppra::solver::seidel::internal::project_linear_constraint(toppra::solver::RowVector3 { -1., 0., low[0] },
        d_tan, zero_prj, A_1d.row(i));
    // handle x <= high
    toppra::solver::seidel::internal::project_linear_constraint(toppra::solver::RowVector3 { 1., 0., -high[0] },
        d_tan, zero_prj, A_1d.row(i+1));
    // handle low <= y
    toppra::solver::seidel::internal::project_linear_constraint(toppra::solver::RowVector3 { 0., -1., low[1] },
        d_tan, zero_prj, A_1d.row(i+2));
    // handle y <= high
    toppra::solver::seidel::internal::project_linear_constraint(toppra::solver::RowVector3 { 0., 1., -high[1] },
        d_tan, zero_prj, A_1d.row(i+3));

    // solve the projected, 1 dimensional LP
    toppra::solver::seidel::LpSol1d sol_1d = toppra::solver::seidel::solve_lp1d(v_1d, A_1d.topRows(4+i));

    if (!sol_1d.feasible) {
      printf("[WARN] -> infeasible 2");
      return;
    }

    // feasible, wrapping up
    // compute the current optimal solution
    cur_optvar = zero_prj + sol_1d.optvar * d_tan;
  }

  // Sanity check for debugging purpose.
  for (int i = 0; i < nrows; ++i) {
    double v = toppra::solver::seidel::value(A.row(i), cur_optvar);
    if (v > 0.0) {
    }
  }


  // Fill the solution struct
  sol.feasible = true;
  sol.optvar = cur_optvar;
  sol.optval = v * sol.optvar;
}

bool SeidelParallelSolveStagewiseBatchHLS(size_t N, 
    toppra::solver::MatricesX3 m_A, 
    toppra::solver::MatrixX2 m_low, 
    toppra::solver::MatrixX2 m_high, 
    std::vector<toppra::solver::seidel::LpSol>& m_solution_upper, 
    std::vector<toppra::solver::seidel::LpSol>& m_solution_lower)
{
  toppra::Vector g_upper{2}, g_lower{2};
  g_upper << -1e-9, 1;
  g_lower << 1e-9, -1;
  toppra::solver::RowVector2 v_upper (g_upper.head<2>());
  toppra::solver::RowVector2 v_lower (g_lower.head<2>());

  bool batch_ok = true;
  for (int i = 0; i < N; i++) {
    solve_lp2d_parallel_hls(v_upper, m_A[i], m_low.row(i), m_high.row(i), m_solution_upper[i]);
    if (!m_solution_upper[i].feasible) {
      printf("Fail: solveStagewiseBatch, upper problem, idx: %d\n", i);
      batch_ok = false;
    }

    solve_lp2d_parallel_hls(v_lower, m_A[i], m_low.row(i), m_high.row(i), m_solution_lower[i]);
    if (!m_solution_lower[i].feasible) {
      printf("Fail: solveStagewiseBatch, lower problem, idx: %d\n", i);
      batch_ok = false;
    }
  }
  return batch_ok;
}
