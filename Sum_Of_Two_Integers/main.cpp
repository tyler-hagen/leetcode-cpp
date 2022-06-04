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

TEST(Sum_Of_Two_Integers, general_case_2)
{
    int a = 2, b = 3;
    Solution s;
    int expected = 5;

    int actual = s.getSum(a, b);
    EXPECT_EQ(actual, expected);
}

TEST(Sum_Of_Two_Integers, positive_and_negative)
{
    int a = 2, b = -3;
    Solution s;
    int expected = -1;

    int actual = s.getSum(a, b);
    EXPECT_EQ(actual, expected);
}

TEST(Sum_Of_Two_Integers, positive_greater_and_negative)
{
    int a = 5, b = -3;
    Solution s;
    int expected = 2;

    int actual = s.getSum(a, b);
    EXPECT_EQ(actual, expected);
}

TEST(Sum_Of_Two_Integers, two_negatives)
{
    int a = -2, b = -3;
    Solution s;
    int expected = -5;

    int actual = s.getSum(a, b);
    EXPECT_EQ(actual, expected);
}

TEST(Sum_Of_Two_Integers, one_and_neg_one)
{
    int a = -1, b = 1;
    Solution s;
    int expected = 0;

    int actual = s.getSum(a, b);
    EXPECT_EQ(actual, expected);
}