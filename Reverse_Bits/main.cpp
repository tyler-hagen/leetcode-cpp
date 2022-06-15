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

TEST(Reverse_Bits, general_case)
{
    uint32_t input = 0b00000010100101000001111010011100;
    Solution s;
    int expected = 0b00111001011110000010100101000000;

    int actual = s.reverseBits(input);
    EXPECT_EQ(actual, expected);
}