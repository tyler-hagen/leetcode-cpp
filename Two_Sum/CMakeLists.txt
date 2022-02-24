cmake_minimum_required(VERSION 3.10)

project(Two_Sum)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

add_subdirectory($ENV{GTEST_BASE_PATH} $ENV{GTEST_BASE_PATH}/build)
include_directories(/Users/tylerhagen/Projects/googletest/googletest/include)

link_libraries(gtest)

add_executable(Two_Sum main.cpp solution.h)