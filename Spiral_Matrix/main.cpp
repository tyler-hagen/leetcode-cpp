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

TEST(Spiral_Matrix, general_case)
{
    // arrange
    vector<vector<int>> inputMatrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> expected = {1,2,3,6,9,8,7,4,5};
    Solution s;

    // run
    auto actual = s.spiralOrder(inputMatrix);

    // assert
    EXPECT_EQ(actual, expected);
}

TEST(Spiral_Matrix, second_case)
{
    // arrange
    vector<vector<int>> inputMatrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> expected = {1,2,3,4,8,12,11,10,9,5,6,7};
    Solution s;

    // run
    auto actual = s.spiralOrder(inputMatrix);

    // assert
    EXPECT_EQ(actual, expected);
}

TEST(Spiral_Matrix, one_column)
{
    // arrange
    vector<vector<int>> inputMatrix = {{3},{2}};
    vector<int> expected = {3,2};
    Solution s;

    // run
    auto actual = s.spiralOrder(inputMatrix);

    // assert
    EXPECT_EQ(actual, expected);
}