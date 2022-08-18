#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(Reduce_Array_Size_To_Half, general_case)
{
    // arrange
    vector<int> arr = {3,3,3,3,5,5,5,2,2,7};
    Solution s;
    auto expected = 2;

    //run
    auto actual = s.minSetSize(arr);
    
    //assert
    EXPECT_EQ(actual, expected);
}

TEST(Reduce_Array_Size_To_Half, only_sevens)
{
    // arrange
    vector<int> arr = {7,7,7,7,7,7};
    Solution s;
    auto expected = 1;

    //run
    auto actual = s.minSetSize(arr);
    
    //assert
    EXPECT_EQ(actual, expected);
}