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

TEST(Substring_With_Concatenation_All_Words, general_case)
{
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    Solution sol;
    vector<int> expected = {0,9};

    auto actual = sol.findSubstring(s, words);
    EXPECT_EQ(actual, expected);
}

TEST(Substring_With_Concatenation_All_Words, empty_case)
{
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","word"};
    Solution sol;
    vector<int> expected = {};

    auto actual = sol.findSubstring(s, words);
    EXPECT_EQ(actual, expected);
}

TEST(Substring_With_Concatenation_All_Words, general_case_2)
{
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar","foo","the"};
    Solution sol;
    vector<int> expected = {6,9,12};

    auto actual = sol.findSubstring(s, words);
    EXPECT_EQ(actual, expected);
}