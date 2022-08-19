#include <vector>
#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main()
{

    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(Three_Sum, general_case)
{
    // arrange
    vector<int> nums {1,2,3,3,4,5};
    Solution s;

    // run
    bool actual = s.isPossible(nums);

    // assert
    EXPECT_TRUE(actual);
}

TEST(Three_Sum, general_case_2)
{
    // arrange
    vector<int> nums {1,2,3,3,4,4,5,5};
    Solution s;

    // run
    bool actual = s.isPossible(nums);

    // assert
    EXPECT_TRUE(actual);
}
