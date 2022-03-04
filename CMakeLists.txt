cmake_minimum_required(VERSION 3.10)
project(Tests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

add_subdirectory($ENV{GTEST_BASE_PATH} $ENV{GTEST_BASE_PATH}/build)
include_directories($ENV{GTEST_BASE_PATH}/googletest/include)
link_libraries(gtest)

add_subdirectory(Two_Sum ../Two_Sum/build)
add_subdirectory(Best_Stock ../Best_Stock/build)