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

TEST(N_Queens, general_case)
{
    int input = 4; 
    Solution s;
    vector<vector<string>> expected = {{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}}; 

    auto actual = s.solveNQueens(input);
    EXPECT_EQ(actual, expected);
}

TEST(N_Queens, 1_CASE)
{
    int input = 1; 
    Solution s;
    vector<vector<string>> expected = {{"Q"}}; 

    auto actual = s.solveNQueens(input);
    EXPECT_EQ(actual, expected);
}