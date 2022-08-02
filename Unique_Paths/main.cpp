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

TEST(Unique_Paths, general_case)
{
    int m = 3, n = 7;
    Solution s;
    int expected = 28;

    int actual = s.uniquePaths(m, n);
    EXPECT_EQ(actual, expected);
}

TEST(Unique_Paths, general_case_2)
{
    int m = 9, n = 11;
    Solution s;
    int expected = 28;

    int actual = s.uniquePaths(m, n);
    EXPECT_EQ(actual, expected);
}