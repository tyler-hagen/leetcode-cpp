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

TEST(Valid_Palindrome, general_case)
{
    // arrange
    string input = "A man, a plan, a canal: Panama";
    Solution sol;

    // run
    bool actual = sol.isPalindrome(input);

    // assert
    EXPECT_TRUE(actual);
}

TEST(Valid_Palindrome, general_case_2)
{
    // arrange
    string input = "race a car";
    Solution sol;

    // run
    bool actual = sol.isPalindrome(input);

    // assert
    EXPECT_FALSE(actual);
}

TEST(Valid_Palindrome, empty_case)
{
    // arrange
    string input = " ";
    Solution sol;

    // run
    bool actual = sol.isPalindrome(input);

    // assert
    EXPECT_TRUE(actual);
}

TEST(Valid_Palindrome, aa_case)
{
    // arrange
    string input = "aa";
    Solution sol;

    // run
    bool actual = sol.isPalindrome(input);

    // assert
    EXPECT_TRUE(actual);
}

TEST(Valid_Palindrome, alphanumeric)
{
    // arrange
    string input = "0P";
    Solution sol;

    // run
    bool actual = sol.isPalindrome(input);

    // assert
    EXPECT_FALSE(actual);
}