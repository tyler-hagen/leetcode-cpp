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

TEST(Maximum_Subarray, general_case)
{
    // arrange
    vector<int> inputVector {2, 3, -2, 4};
    int expected = 6;
    Solution s;

    //run
    int actual = s.maxProduct(inputVector);

    EXPECT_EQ(actual, expected);
}

TEST(Maximum_Subarray, with_zero)
{
    // arrange
    vector<int> inputVector {-2, 0, -1};
    int expected = 0;
    Solution s;

    //run
    int actual = s.maxProduct(inputVector);

    EXPECT_EQ(actual, expected);
}