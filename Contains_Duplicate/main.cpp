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
    vector<int> inputVector {7, 1, 5, 3, 6, 4, 1};
    bool expected = true;
    Solution s;

    //run
    bool actual = s.containsDuplicate(inputVector);

    EXPECT_EQ(actual, expected);
}