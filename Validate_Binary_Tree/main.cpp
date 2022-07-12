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

TEST(Validate_Binary_Tree, general_case)
{
    // arrange
    vector<long long> input = {5,4,6,INT64_MIN,INT64_MIN,3,7};
    TreeNode* inputTree = generateTreeFromVector(input);
    Solution s;

    //run
    auto actual = s.isValidBST(inputTree);

    EXPECT_FALSE(actual);
}

TEST(Validate_Binary_Tree, general_case_2)
{
    // arrange
    vector<long long> input = {3,1,5,0,2,4,6};
    TreeNode* inputTree = generateTreeFromVector(input);
    Solution s;

    //run
    auto actual = s.isValidBST(inputTree);

    EXPECT_TRUE(actual);
}

TEST(Validate_Binary_Tree, general_case_3)
{
    // arrange
    vector<long long> input = {32,26,47,19,INT64_MIN,INT64_MIN,56,INT64_MIN,27};
    TreeNode* inputTree = generateTreeFromVector(input);
    Solution s;

    //run
    auto actual = s.isValidBST(inputTree);

    EXPECT_FALSE(actual);
}

TEST(Validate_Binary_Tree, general_case_4)
{
    // arrange
    vector<long long> input = {2147483644,-2147483648,2147483646,INT64_MIN,INT64_MIN,2147483645,2147483647};
    TreeNode* inputTree = generateTreeFromVector(input);
    Solution s;

    //run
    auto actual = s.isValidBST(inputTree);

    EXPECT_TRUE(actual);
}