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

TEST(Valid_Anagram, general_case)
{
    // arrange
    string s = "anagram";
    string t = "nagaram";
    Solution sol;

    // run
    bool actual = sol.isAnagram(s, t);

    // assert
    EXPECT_TRUE(actual);
}

TEST(Valid_Anagram, false_case)
{
    // arrange
    string s = "rat";
    string t = "car";
    Solution sol;

    // run
    bool actual = sol.isAnagram(s, t);

    // assert
    EXPECT_FALSE(actual);
}