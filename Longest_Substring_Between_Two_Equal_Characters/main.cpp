#include <vector>
#include <iostream>
#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(Longest_Substring_Between_Two_Equal_Characters, zero_case)
{
    // arrange
    string input = "aa";
    Solution s;
    int expected = 0;

    //run
    int actual = s.maxLengthBetweenEqualCharacters(input);

    EXPECT_EQ(actual, expected);
}

TEST(Longest_Substring_Between_Two_Equal_Characters, general_case)
{
    // arrange
    string input = "abca";
    Solution s;
    int expected = 2;

    //run
    int actual = s.maxLengthBetweenEqualCharacters(input);

    EXPECT_EQ(actual, expected);
}

TEST(Longest_Substring_Between_Two_Equal_Characters, no_matching_chars)
{
    // arrange
    string input = "cbzxy";
    Solution s;
    int expected = -1;

    //run
    int actual = s.maxLengthBetweenEqualCharacters(input);

    EXPECT_EQ(actual, expected);
}