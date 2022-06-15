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

TEST(Sum_Of_Two_Integers, general_case)
{
    int a = 1, b = 2;
    Solution s;
    int expected = 3;

    int actual = s.getSum(a, b);
    EXPECT_EQ(actual, expected);
}