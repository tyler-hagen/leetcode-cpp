#include <vector>
#include <iostream>
#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main()
{
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(Two_Sum, general_case)
{
    // arrange
    vector<int> inputVector = {0, -5, 2, 3, 5};
    int inputTarget = 0;
    vector<int> expected = {1, 4};
    Solution s;

    //run
    vector<int> actual = s.twoSum(inputVector, inputTarget);

    EXPECT_EQ(actual, expected);
}

TEST(Two_Sum, same_name_for_answer)
{
    // arrange
    vector<int> inputVector = {0, -5, 2, 3, 4, 0};
    int inputTarget = 0;
    vector<int> expected = {0, 5};
    Solution s;

    //run
    vector<int> actual = s.twoSum(inputVector, inputTarget);

    EXPECT_EQ(actual, expected);
}

