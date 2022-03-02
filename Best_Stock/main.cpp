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

TEST(Best_Stock, general_case)
{
    // arrange
    vector<int> inputVector {7, 1, 5, 3, 6, 4};
    int expected = 5;
    Solution s;

    //run
    int actual = s.maxProfit(inputVector);

    EXPECT_EQ(actual, expected);
}