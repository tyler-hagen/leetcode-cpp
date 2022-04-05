cmake_minimum_required(VERSION 3.10)
project(Tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

add_subdirectory($ENV{GTEST_BASE_PATH} $ENV{GTEST_BASE_PATH}/build)
include_directories($ENV{GTEST_BASE_PATH}/googletest/include)
link_libraries(gtest)

add_subdirectory(Two_Sum ../Two_Sum/build)
add_subdirectory(Best_Stock ../Best_Stock/build)
add_subdirectory(Contains_Duplicate ../Contains_Duplicate/build)
add_subdirectory(Reverse_Linked_List ../Reverse_Linked_List/build)
add_subdirectory(Product_Of_Array_Except_Self ../Product_Of_Array_Except_Self/build)
add_subdirectory(Maximum_Subarray ../Maximum_Subarray/build)