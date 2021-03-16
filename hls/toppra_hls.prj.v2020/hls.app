<project xmlns="com.autoesl.autopilot.project" name="toppra_hls.prj.v2020" top="SeidelParallelSolveStagewiseBatchHLS">
    <includePaths/>
    <libraryPaths/>
    <Simulation argv="">
        <SimFlow name="csim" optimizeCompile="true" ldflags="-L../../../../../hls/lib -ltopprah -lgtest -Wl,-rpath,../../../../../hls/lib" clean="true" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <files xmlns="">
        <file name="../../../source/tests/gtest_main.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" csimflags=" -I../../../../../source/src  -I../../../../../source/build/src  -I../../../../../source/tests  -I../../../../../../../usr/local/include/eigen3  -Wno-unknown-pragmas" blackbox="false"/>
        <file name="../../../source/tests/test_parallel_approach.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" csimflags=" -I../../../../../source/src  -I../../../../../source/build/src  -I../../../../../source/tests  -I../../../../../../../usr/local/include/eigen3  -Wno-unknown-pragmas" blackbox="false"/>
        <file name="src/toppra/solver/seidel-parallel-hls.cpp" sc="0" tb="false" cflags="" csimflags="-I../../../source/src -I../../../source/build/src -I/usr/local/include/eigen3" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="solution1" status="active"/>
    </solutions>
</project>

