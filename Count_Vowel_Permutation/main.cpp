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

TEST(Count_Vowels_Permutation, case_1)
{
    int input = 1;
    Solution s;
    int expected = 5;

    int actual = s.countVowelPermutation(input);
    EXPECT_EQ(actual, expected);
}

TEST(Count_Vowels_Permutation, case_2)
{
    int input = 2;
    Solution s;
    int expected = 10;

    int actual = s.countVowelPermutation(input);
    EXPECT_EQ(actual, expected);
}

TEST(Count_Vowels_Permutation, case_5)
{
    int input = 5;
    Solution s;
    int expected = 68;

    int actual = s.countVowelPermutation(input);
    EXPECT_EQ(actual, expected);
}

TEST(Count_Vowels_Permutation, overflow_case)
{
    int input = 144;
    Solution s;
    int expected = 68;

    int actual = s.countVowelPermutation(input);
    EXPECT_EQ(actual, expected);
}

