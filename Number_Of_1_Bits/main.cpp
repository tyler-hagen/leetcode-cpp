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

TEST(Number_Of_1_Bits, general_case)
{
    uint32_t n = 0b00000000000000000000000000001011;
    Solution s;
    int expected = 3;

    int actual = s.hammingWeight(n);
    EXPECT_EQ(actual, expected);
}