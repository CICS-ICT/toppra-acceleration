# Description
This is an implementation of the TOPP-RA algorithm. ([Github](https://github.com/js00000/toppra))

# Building Tests

```sh

# build
export LD_LIBRARY_PATH=/opt/openrobots/lib:${LD_LIBRARY_PATH}
export CMAKE_PREFIX_PATH=/opt/openrobots
mkdir build
cd build
cmake ..
make -j4

# run test
./tests/all_tests
```