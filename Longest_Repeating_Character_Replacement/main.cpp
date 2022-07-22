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

TEST(Longest_Repeating_Character_Replacement, general_case)
{
    // arrange
    string input = "ABAB";
    int k = 2;
    Solution s;
    int expected = 4;

    // run
    int actual = s.characterReplacement(input, k);

    // assert
    EXPECT_EQ(actual, expected);
}

TEST(Longest_Repeating_Character_Replacement, general_case_2)
{
    // arrange
    string input = "AABABBA";
    int k = 1;
    Solution s;
    int expected = 4;

    // run
    int actual = s.characterReplacement(input, k);

    // assert
    EXPECT_EQ(actual, expected);
}

TEST(Longest_Repeating_Character_Replacement, replacement_starts_left)
{
    // arrange
    string input = "ABBB";
    int k = 2;
    Solution s;
    int expected = 4;

    // run
    int actual = s.characterReplacement(input, k);

    // assert
    EXPECT_EQ(actual, expected);
}

TEST(Longest_Repeating_Character_Replacement, replacement_left_and_right)
{
    // arrange
    string input = "BAAAB";
    int k = 2;
    Solution s;
    int expected = 5;

    // run
    int actual = s.characterReplacement(input, k);

    // assert
    EXPECT_EQ(actual, expected);
}