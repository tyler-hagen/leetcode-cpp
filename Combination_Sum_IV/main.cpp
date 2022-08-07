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

TEST(Combination_Sum_IV, general_case)
{
    vector<int> nums = {1, 2, 3};
    int target = 4;
    Solution s;
    int expected = 7;

    int actual = s.combinationSum4(nums, target);
    EXPECT_EQ(actual, expected);
}

TEST(Combination_Sum_IV, zero_case)
{
    vector<int> nums = {9};
    int target = 3;
    Solution s;
    int expected = 0;

    int actual = s.combinationSum4(nums, target);
    EXPECT_EQ(actual, expected);
}