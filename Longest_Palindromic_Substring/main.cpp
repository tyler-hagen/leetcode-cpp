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

TEST(Longest_Palindromic_Substring, general_case)
{
    // arrange
    string input = "babad";
    Solution s;
    string expected = "bab";

    // run
    string actual = s.longestPalindrome(input);

    // assert
    EXPECT_EQ(actual, expected);
}

TEST(Longest_Palindromic_Substring, general_case_2)
{
    // arrange
    string input = "cbbd";
    Solution s;
    string expected = "bb";

    // run
    string actual = s.longestPalindrome(input);

    // assert
    EXPECT_EQ(actual, expected);
}

TEST(Longest_Palindromic_Substring, general_case_3)
{
    // arrange
    string input = "aacabdkacaa";
    Solution s;
    string expected = "aca";

    // run
    string actual = s.longestPalindrome(input);

    // assert
    EXPECT_EQ(actual, expected);
}