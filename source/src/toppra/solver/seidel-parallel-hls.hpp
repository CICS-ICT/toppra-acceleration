#ifndef TOPPRA_SOLVER_SEIDEL_PARALLEL_HLS_HPP
#define TOPPRA_SOLVER_SEIDEL_PARALLEL_HLS_HPP

#include <toppra/solver.hpp>
#include <toppra/solver/seidel-internal.hpp>

void solve_lp2d_parallel_hls(const toppra::solver::RowVector2 v, 
    const toppra::solver::MatrixX3& A, 
    const toppra::solver::Vector2& low, 
    const toppra::solver::Vector2& high, 
    toppra::solver::seidel::LpSol& sol);

bool SeidelParallelSolveStagewiseBatchHLS(size_t N, 
    toppra::solver::MatricesX3 m_A, 
    toppra::solver::MatrixX2 m_low, 
    toppra::solver::MatrixX2 m_high, 
    std::vector<toppra::solver::seidel::LpSol>& m_solution_upper, 
    std::vector<toppra::solver::seidel::LpSol>& m_solution_lower);

#endif
