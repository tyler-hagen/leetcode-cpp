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

TEST(Kth_Smallest_Element_BST, general_case)
{
    // arrange
    vector<int> input = {3,1,4,INT32_MIN,2};
    TreeNode* inputTree = generateTreeFromVector(input);
    int k = 1;
    int expected = 1;
    Solution s;

    //run
    auto actual = s.kthSmallest(inputTree, k);

    EXPECT_EQ(actual, expected);
}

TEST(Kth_Smallest_Element_BST, general_case_2)
{
    // arrange
    vector<int> input = {5,3,6,2,4,INT32_MIN,INT32_MIN,1};

    TreeNode* inputTree = generateTreeFromVector(input);
    int k = 3;
    int expected = 3;
    Solution s;

    //run
    auto actual = s.kthSmallest(inputTree, k);

    EXPECT_EQ(actual, expected);
}