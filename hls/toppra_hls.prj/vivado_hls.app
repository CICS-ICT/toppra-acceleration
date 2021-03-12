<project xmlns="com.autoesl.autopilot.project" name="toppra_hls.prj" top="SeidelParallelSolveStagewiseBatchHLS">
    <files>
        <file name="src/toppra/solver/seidel-parallel-hls.cpp" sc="0" tb="false" cflags="-I../../../source/src -I../../../source/build/src -I/usr/local/include/eigen3"/>
        <file name="../../../source/tests/gtest_main.cpp" sc="0" tb="1" cflags="-I../../../source/src -I../../../source/build/src -I../../../source/tests -I/usr/local/include/eigen3 -I/opt/openrobots/include"/>
        <file name="../../../source/tests/test_parallel_approach.cpp" sc="0" tb="1" cflags="-DBUILD_WITH_qpOASES -I../../../source/src -I../../../source/build/src -I../../../source/tests -I/usr/local/include/eigen3 -I/opt/openrobots/include"/>
    </files>
    <includePaths/>
    <libraryPaths/>
    <Simulation argv="">
        <SimFlow name="csim" optimizeCompile="true" ldflags="-L../../../../../hls/lib -ltopprah -lgtest -L/opt/openrobots/lib -lqpOASES -Wl,-rpath,../../../../../hls/lib" clean="true" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <solutions xmlns="">
        <solution name="solution1" status="active"/>
    </solutions>
</project>

