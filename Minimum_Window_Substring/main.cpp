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
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;
    string expected = "BANC";

    // run
    string actual = sol.minWindow(s, t);

    // assert
    EXPECT_EQ(actual, expected);
}

TEST(Longest_Repeating_Character_Replacement, one_char)
{
    // arrange
    string s = "a";
    string t = "a";
    Solution sol;
    string expected = "a";

    // run
    string actual = sol.minWindow(s, t);

    // assert
    EXPECT_EQ(actual, expected);
}

TEST(Longest_Repeating_Character_Replacement, no_answer)
{
    // arrange
    string s = "a";
    string t = "aa";
    Solution sol;
    string expected = "";

    // run
    string actual = sol.minWindow(s, t);

    // assert
    EXPECT_EQ(actual, expected);
}