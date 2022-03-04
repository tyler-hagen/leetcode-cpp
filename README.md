# leetcode-cpp

This project contains solutions to leetcode problems implemented in C++. Google Test is used to unit test the solutions outside of the leetcode environment.

Each solution folder contains a solution.h file which contains the solution to a given problem. The solution is done like this so it can easily be copy-pasted into leetcode. A main.cpp file also exists which is used to define unit tests using Google Test.

## Build and run a solution

### Google test (do this once)
- clone google test into a folder outside of this repo: https://github.com/google/googletest
- in the google test repository: `git checkout release-1.11.0`
- set an environment variable called GTEST_BASE_PATH that points to the directory where you cloned googletest to.

### Build solutions
In the repository root: 
- `mkdir build`
- `cd build`
- `cmake ..` (This is known as an "out of source" build?)
- `cmake --build .`

### Run a solution
- `cd <problem directory>` (example: `cd Two_Sum`)
- `cd build`
- `.\<problem>` (example: `./Two_Sum`)

The executable simply runs all the tests defined. 

## Adding a new solution
