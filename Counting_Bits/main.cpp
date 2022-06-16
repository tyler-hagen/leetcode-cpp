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

TEST(Counting_Bits, general_case)
{
    int input = 2;
    Solution s;
    vector<int> expected = {0, 1, 1};

    auto actual = s.countBits(input);
    EXPECT_EQ(actual, expected);
}

TEST(Counting_Bits, general_case_2)
{
    int input = 5;
    Solution s;
    vector<int> expected = {0, 1, 1, 2, 1, 2};

    auto actual = s.countBits(input);
    EXPECT_EQ(actual, expected);
}