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
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"e","o"};
    Solution sol;
    vector<string> expected = {"facebook","google","leetcode"};

    // run
    vector<string> actual = sol.wordSubsets(words1, words2);

    // assert
    EXPECT_EQ(actual, expected);
}

TEST(Longest_Palindromic_Substring, general_case_2)
{
    // arrange
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"l","e"};
    Solution sol;
    vector<string> expected = {"apple","google","leetcode"};

    // run
    vector<string> actual = sol.wordSubsets(words1, words2);

    // assert
    EXPECT_EQ(actual, expected);
}
