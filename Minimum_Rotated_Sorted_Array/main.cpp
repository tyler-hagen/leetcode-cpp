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

TEST(Minimum_Rotated_Sorted_Array, general_case)
{
    // arrange
    vector<int> inputVector {3, 4, 5, 1, 2};
    int expected = 1;
    Solution s;

    //run
    int actual = s.findMin(inputVector);

    EXPECT_EQ(actual, expected);
}

TEST(Minimum_Rotated_Sorted_Array, with_zero)
{
    // arrange
    vector<int> inputVector {4,5,6,7,0,1,2};
    int expected = 0;
    Solution s;

    //run
    int actual = s.findMin(inputVector);

    EXPECT_EQ(actual, expected);
}

TEST(Minimum_Rotated_Sorted_Array, general_case_2)
{
    // arrange
    vector<int> inputVector {11,13,15,17};
    int expected = 11;
    Solution s;

    //run
    int actual = s.findMin(inputVector);

    EXPECT_EQ(actual, expected);
}

TEST(Minimum_Rotated_Sorted_Array, transition_far_right)
{
    // arrange
    vector<int> inputVector {13,15,17,11};
    int expected = 11;
    Solution s;

    //run
    int actual = s.findMin(inputVector);

    EXPECT_EQ(actual, expected);
}