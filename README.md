# leetcode-cpp

This project contains solutions to leetcode problems implemented in C++. Google Test is used to unit test the solutions outside of the leetcode environment.

Each solution folder contains a solution.h file which contains the solution to a given problem. The solution is done like this so it can easily be copy-pasted into leetcode. A main.cpp file also exists which is used to define unit tests using Google Test. Each solution folder produces its own executable independent of the other solutions.

Intellisense & debugging are supported in vscode.

## Build and run a solution

### Google test (do this once)
- clone google test into a folder outside of this repo: https://github.com/google/googletest
- in the google test repository: `git checkout release-1.11.0`
- set an environment variable called GTEST_BASE_PATH that points to the directory where you cloned googletest to.

### Build all solutions
In the repository root: 
- `mkdir build`
- `cd build`
- `cmake ..`
- `cmake --build .`

### Run a solution
- `cd <problem directory>` (example: `cd Two_Sum`)
- `cd build`
- `.\<problem>` (example: `./Two_Sum`)

The executable simply runs all the tests defined. 
You can rebuild the program by just running `make` in this build repo

### Debug a solution
Debugging should work in vscode by hitting f5 on either the main.cpp or solution.h for a given solution folder.

## Adding a new solution
In the repository root:
- `mkdir Problem_Name`
- copy an existing problems CMakeLists.txt, main.cpp, solution.h into the new directory
- change the project and executable name in CMakeLists.txt to the problem name
- clear out the tests in main.cpp
- copy the solution class from leetcode into solution.h
- in the root CMakeLists.txt, add the new problem directory as a subdirectory like the other solutions
- in the root `build` folder run `cmake .. && cmake --build .` again

## Todo
- Move helper functions to own shared lib?