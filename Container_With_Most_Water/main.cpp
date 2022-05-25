#include <vector>
#include <iostream>
#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main()
{
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(Container_With_Most_Water, general_case)
{
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    Solution s;
    int expected = 49;

    int actual = s.maxArea(heights);
    EXPECT_EQ(actual, expected);
}