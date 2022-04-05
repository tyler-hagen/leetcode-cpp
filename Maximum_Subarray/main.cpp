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

TEST(Contains_Duplicate, general_case)
{
    // arrange
    vector<int> inputVector {-2,1,-3,4,-1,2,1,-5,4};
    int expected = 6;
    Solution s;

    //run
    int actual = s.maxSubArray(inputVector);

    EXPECT_EQ(actual, expected);
}

TEST(Contains_Duplicate, one_element)
{
    // arrange
    vector<int> inputVector {1};
    int expected = 1;
    Solution s;

    //run
    int actual = s.maxSubArray(inputVector);

    EXPECT_EQ(actual, expected);
}

TEST(Contains_Duplicate, one_element_negative)
{
    // arrange
    vector<int> inputVector {-5};
    int expected = -5;
    Solution s;

    //run
    int actual = s.maxSubArray(inputVector);

    EXPECT_EQ(actual, expected);
}

TEST(Contains_Duplicate, general_case_2)
{
    // arrange
    vector<int> inputVector {5,4,-1,7,8};
    int expected = 23;
    Solution s;

    //run
    int actual = s.maxSubArray(inputVector);

    EXPECT_EQ(actual, expected);
}