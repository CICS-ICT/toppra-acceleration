############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project toppra_hls.prj.v2020
set_top SeidelParallelSolveStagewiseBatchHLS
add_files src/toppra/solver/seidel-parallel-hls.cpp -csimflags "-I../../../source/src -I../../../source/build/src -I/usr/local/include/eigen3"
add_files -tb ../source/tests/gtest_main.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-I../../../source/src -I../../../source/build/src -I../../../source/tests -I../../../../../usr/local/include/eigen3 -Wno-unknown-pragmas"
add_files -tb ../source/tests/test_parallel_approach.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-I../../../source/src -I../../../source/build/src -I../../../source/tests -I../../../../../usr/local/include/eigen3 -Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
#source "./toppra_hls.prj.v2020/solution1/directives.tcl"
csim_design -ldflags {-L../../../../../hls/lib -ltopprah -lgtest -Wl,-rpath,../../../../../hls/lib} -clean -O
csynth_design
cosim_design -ldflags {-L../../../../../hls/lib -ltopprah -lgtest -Wl,-rpath,../../../../../hls/lib}
export_design -format ip_catalog
