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

TEST(Missing_Number, general_case)
{
    vector<int> input = {3, 0 , 1};
    Solution s;
    int expected = 2;

    int actual = s.missingNumber(input);
    EXPECT_EQ(actual, expected);
}

TEST(Missing_Number_XOR, general_case)
{
    vector<int> input = {3, 0 , 1};
    Solution s;
    int expected = 2;

    int actual = s.missingNumberXOR(input);
    EXPECT_EQ(actual, expected);
}