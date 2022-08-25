#include <vector>
#include <iostream>
#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

TEST(Set_Matrix_Zeroes, general_case)
{
    // arrange
    vector<vector<int>> inputMatrix = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> expected = {{1,0,1},{0,0,0},{1,0,1}};
    Solution s;

    // run
    s.setZeroes(inputMatrix);

    // assert
    EXPECT_EQ(inputMatrix, expected);
}

TEST(Set_Matrix_Zeroes, second_case)
{
    // arrange
    vector<vector<int>> inputMatrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<vector<int>> expected = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
    Solution s;

    // run
    s.setZeroes(inputMatrix);

    // assert
    EXPECT_EQ(inputMatrix, expected);
}

TEST(Set_Matrix_Zeroes, one_column_case)
{
    // arrange
    vector<vector<int>> inputMatrix = {{1},{0}};
    vector<vector<int>> expected = {{0},{0}};
    Solution s;

    // run
    s.setZeroes(inputMatrix);

    // assert
    EXPECT_EQ(inputMatrix, expected);
}