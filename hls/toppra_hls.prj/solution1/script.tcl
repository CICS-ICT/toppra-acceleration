############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project toppra_hls.prj
set_top SeidelParallelSolveStagewiseBatchHLS
add_files src/toppra/solver/seidel-parallel-hls.cpp -cflags "-I../../../source/src -I../../../source/build/src -I/usr/local/include/eigen3"
add_files -tb ../source/tests/gtest_main.cpp -cflags "-I../source/src -I../source/build/src -I../source/tests -I/usr/local/include/eigen3 -I/opt/openrobots/include"
add_files -tb ../source/tests/test_parallel_approach.cpp -cflags "-DBUILD_WITH_qpOASES -I../source/src -I../source/build/src -I../source/tests -I/usr/local/include/eigen3 -I/opt/openrobots/include"
open_solution "solution1"
set_part {xc7z020clg400-1} -tool vivado
create_clock -period 10 -name default
#source "./toppra_hls.prj/solution1/directives.tcl"
csim_design -ldflags {-L../../../../../hls/lib -ltopprah -lgtest -L/opt/openrobots/lib -lqpOASES -Wl,-rpath,../../../../../hls/lib} -clean -O
csynth_design
cosim_design -ldflags {-L../../../../../hls/lib -ltopprah -lgtest -L/opt/openrobots/lib -lqpOASES -Wl,-rpath,../../../../../hls/lib}
export_design -format ip_catalog
