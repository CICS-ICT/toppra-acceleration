#ifndef TOPPRA_SOLVER_SEIDEL_PARALLEL_HPP
#define TOPPRA_SOLVER_SEIDEL_PARALLEL_HPP

#include <omp.h>
#include <memory.h>
#include <toppra/solver.hpp>
#include <toppra/solver/seidel-internal.hpp>

namespace toppra {
namespace solver {

/** Implementation of SeidelParallel algorithm.
 *
 * */
class SeidelParallel : public Solver {
  public:
    SeidelParallel () = default;

    void solve_lp2d_parallel(bool isback, const RowVector2 v, const MatrixX3& A,
        const Vector2& low, const Vector2& high, MatrixX2& A_1d, seidel::LpSol& sol);

    void initialize (const LinearConstraintPtrs& constraints, const GeometricPathPtr& path,
        const Vector& times);

    bool solveStagewiseOptim(std::size_t i,
        const Matrix& H, const Vector& g,
        const Bound& x, const Bound& xNext,
        Vector& solution);

    // bool solveStagewiseBatch(Vectors& solution_upper, Vectors& solution_lower);
    bool solveStagewiseBatch();
    bool solveStagewiseBack(int i, bool upper, const Bound& xNext, Vector& solution);

  private:
    size_t nC;
    size_t N;

    Vector g_upper{2}, g_lower{2};
    RowVector2 v_upper, v_lower;

    MatricesX3 m_A;
    MatricesX2 m_A_1d;
    MatrixX2 m_low, m_high;

    std::vector<seidel::LpSol> m_solution_upper;
    std::vector<seidel::LpSol> m_solution_lower;

}; // class SeidelParallel

} // namespace solver
} // namespace toppra

#endif
