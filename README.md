# toppra-acceleration
This is the FPGA acceleration for TOPPRA algorithm.

The theory and application of TOPPRA can be referred to [«A new approach to Time-Optimal Path Parameterization based on Reachability Analysis»](https://www.researchgate.net/publication/318671280_A_New_Approach_to_Time-Optimal_Path_Parameterization_Based_on_Reachability_Analysis), *IEEE Transactions on Robotics*, vol. 34(3), pp. 645–659, 2018.

TOPPRA's algorithm is very fast, but for the optimization of robots with large degrees of freedom and long paths, it still cannot meet the delay requirements of real-time control such as MPC when it is executed on the CPU.

We will try to use HLS technology to accelerate it on FPGA to achieve lower power consumption and faster speed.