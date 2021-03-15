<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="com.autoesl.autopilot.project" name="toppra_hls.prj.v2020" top="SeidelParallelSolveStagewiseBatchHLS">
  <files>
    <file name="../../../source/tests/gtest_main.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" blackbox="false" csimflags="-I../../../../../source/src -I../../../../../source/build/src -I../../../../../source/tests -I../../../../../../usr/local/include/eigen3 -Wno-unknown-pragmas"/>
    <file name="../../../source/tests/test_parallel_approach.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" blackbox="false" csimflags="-I../../../../../source/src -I../../../../../source/build/src -I../../../../../source/tests -I../../../../../../usr/local/include/eigen3 -Wno-unknown-pragmas"/>
    <file name="src/toppra/solver/seidel-parallel-hls.cpp" sc="0" tb="false" cflags="" blackbox="false" csimflags="-I../../../source/src -I../../../source/build/src -I/usr/local/include/eigen3"/>
  </files>
  <solutions>
    <solution name="solution1" status="active"/>
  </solutions>
  <includePaths/>
  <libraryPaths/>
  <Simulation argv="">
    <SimFlow name="csim" optimizeCompile="true" ldflags="-L../../../../../hls/lib -ltopprah -lgtest -Wl,-rpath,../../../../../hls/lib" csimMode="0" lastCsimMode="0"/>
  </Simulation>
</project>
