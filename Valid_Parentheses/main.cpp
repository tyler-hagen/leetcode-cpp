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

TEST(Valid_Parentheses, general_case)
{
    // arrange
    string input = "()";
    Solution sol;

    // run
    bool actual = sol.isValid(input);

    // assert
    EXPECT_TRUE(actual);
}

TEST(Valid_Parentheses, general_case_2)
{
    // arrange
    string input = "()[]{}";
    Solution sol;

    // run
    bool actual = sol.isValid(input);

    // assert
    EXPECT_TRUE(actual);
}

TEST(Valid_Parentheses, false_case)
{
    // arrange
    string input = "(]";
    Solution sol;

    // run
    bool actual = sol.isValid(input);

    // assert
    EXPECT_FALSE(actual);
}