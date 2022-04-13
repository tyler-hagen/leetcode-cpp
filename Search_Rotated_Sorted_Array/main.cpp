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

TEST(Search_Rotated_Sorted_Array, general_case)
{
    // arrange
    vector<int> inputVector {4,5,6,7,0,1,2};
    int target = 0; 
    int expected = 4;
    Solution s;

    //run
    int actual = s.search(inputVector, target);

    EXPECT_EQ(actual, expected);
}

TEST(Search_Rotated_Sorted_Array, three_elements)
{
    vector<int> inputVector {5, 1, 3};
    int target = 1;
    int expected = 1;
    Solution s;

    int actual = s.search(inputVector, target);

    EXPECT_EQ(actual, expected);
}

TEST(Search_Rotated_Sorted_Array, two_elements)
{
    vector<int> inputVector {5, 1};
    int target = 1;
    int expected = 1;
    Solution s;

    int actual = s.search(inputVector, target);

    EXPECT_EQ(actual, expected);
}