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

TEST(Group_Anagrams, general_case)
{
    // arrange
    vector<string> input = {"eat","tea","tan","ate","nat","bat"};
    Solution sol;
    vector<vector<string>> expected = {{"bat"}, {"nat", "tan"}, {"ate","eat","tea"}};

    // run
    auto actual = sol.groupAnagrams(input);

    // assert
    EXPECT_EQ(actual, expected);
}

TEST(Group_Anagrams, empty_case)
{
    // arrange
    vector<string> input = {""};
    Solution sol;
    vector<vector<string>> expected = {{""}};

    // run
    auto actual = sol.groupAnagrams(input);

    // assert
    EXPECT_EQ(actual, expected);
}

TEST(Group_Anagrams, one_letter_case)
{
    // arrange
    vector<string> input = {"a"};
    Solution sol;
    vector<vector<string>> expected = {{"a"}};

    // run
    auto actual = sol.groupAnagrams(input);

    // assert
    EXPECT_EQ(actual, expected);
}