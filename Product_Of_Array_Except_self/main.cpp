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

TEST(Product_Of_Array_Except_Self, general_case)
{
    // arrange
    vector<int> inputVector {1, 2, 3, 4};
    vector<int> expected {24, 12, 8, 6};
    Solution s;

    //run
    auto actual = s.productExceptSelf(inputVector);

    EXPECT_EQ(actual, expected);
}