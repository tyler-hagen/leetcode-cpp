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

TEST(Longest_Increasing_Subsequence, general_case)
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution s;
    int expected = 4;

    int actual = s.lengthOfLIS(nums);
    EXPECT_EQ(actual, expected);
}