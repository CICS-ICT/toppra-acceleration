<project xmlns="com.autoesl.autopilot.project" top="SeidelParallelSolveStagewiseBatchHLS" name="toppra_hls.prj">
    <files>
        <file name="src/toppra/solver/seidel-parallel-hls.cpp" sc="0" tb="false" cflags="-I/home/pnpeasy/Workspace/toppra-acceleration/source/src -I/usr/local/include/eigen3 -I/home/pnpeasy/Workspace/toppra-acceleration/source/build/src"/>
        <file name="../../../source/tests/gtest_main.cpp" sc="0" tb="1" cflags="-I../../../source/build/src -I../../../source/tests -I../../../source/src -I../../../../../../../usr/local/include/eigen3 -I../../../../../../../opt/openrobots/include"/>
        <file name="../../../source/tests/test_parallel_approach.cpp" sc="0" tb="1" cflags="-I../../../source/build/src -I../../../source/tests -I../../../source/src -I../../../../../../../usr/local/include/eigen3 -I../../../../../../../opt/openrobots/include"/>
    </files>
    <includePaths/>
    <libraryPaths/>
    <Simulation argv="">
        <SimFlow name="csim" optimizeCompile="true" ldflags="-L/home/pnpeasy/Workspace/toppra-acceleration/hls/lib -ltopprah -L/opt/openrobots/lib -lqpOASES /home/pnpeasy/Workspace/toppra-acceleration/hls/lib/libgtest.a -Wl,-rpath,/home/pnpeasy/Workspace/toppra-acceleration/hls/lib" clean="true" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <solutions xmlns="">
        <solution name="solution1" status="active"/>
    </solutions>
</project>

