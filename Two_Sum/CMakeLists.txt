cmake_minimum_required(VERSION 3.10)
enable_testing()
project(Two_Sum)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

add_executable(Two_Sum tests.cpp)

include(GoogleTest)
gtest_discover_tests(Two_Sum)