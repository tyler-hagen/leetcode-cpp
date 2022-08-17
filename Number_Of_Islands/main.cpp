#include <vector>
#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

TEST(Number_Of_Islands, general_case)
{
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    Solution s;
    int expected = 1;

    auto actual = s.numIslands(grid);
    EXPECT_EQ(actual, expected);
}

TEST(Number_Of_Islands, general_case_2)
{
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution s;
    int expected = 3;

    auto actual = s.numIslands(grid);
    EXPECT_EQ(actual, expected);
}