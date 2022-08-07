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

TEST(Mirror_Reflection, general_case)
{

    int p = 2, q = 1;
    Solution s;
    int expected = 2;

    int actual = s.mirrorReflection(p, q);
    EXPECT_EQ(actual, expected);
}

TEST(Mirror_Reflection, general_case_2)
{

    int p = 3, q = 1;
    Solution s;
    int expected = 1;

    int actual = s.mirrorReflection(p, q);
    EXPECT_EQ(actual, expected);
}