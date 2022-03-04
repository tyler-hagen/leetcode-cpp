cmake_minimum_required(VERSION 3.10)

project(Best_Stock)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

add_executable(Best_Stock main.cpp solution.h)

include(GoogleTest)
gtest_discover_tests(Best_Stock)