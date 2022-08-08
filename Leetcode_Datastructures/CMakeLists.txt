cmake_minimum_required(VERSION 3.10)

project(Leetcode_Datastructures)

add_library(Leetcode_Datastructures STATIC Node.cpp)
add_executable(NodeTests Tests/NodeTests.cpp Node.cpp) 