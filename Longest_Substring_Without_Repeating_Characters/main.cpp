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

TEST(Longest_Substring_Without_Repeating_Characters, general_case)
{
    // arrange
    string input = "abcabcbb";
    Solution s;
    int expected = 3;

    //run
    int actual = s.lengthOfLongestSubstring(input);

    EXPECT_EQ(actual, expected);
}

TEST(Longest_Substring_Without_Repeating_Characters, bs_only_case)
{
    // arrange
    string input = "bbbbb";
    Solution s;
    int expected = 1;

    //run
    int actual = s.lengthOfLongestSubstring(input);

    EXPECT_EQ(actual, expected);
}

TEST(Longest_Substring_Without_Repeating_Characters, general_case_2)
{
    // arrange
    string input = "pwwkew";
    Solution s;
    int expected = 3;

    //run
    int actual = s.lengthOfLongestSubstring(input);

    EXPECT_EQ(actual, expected);
}

TEST(Longest_Substring_Without_Repeating_Characters, remove_old_hashmap_entries)
{
    // arrange
    string input = "abba";
    Solution s;
    int expected = 2;

    //run
    int actual = s.lengthOfLongestSubstring(input);

    EXPECT_EQ(actual, expected);
}