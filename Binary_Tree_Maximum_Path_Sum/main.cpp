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

TEST(Binary_Tree_Maximum_Path_Sum, general_case)
{
    // arrange
    vector<int> inputVector {1, 2, 3};
    TreeNode* inputNode = generateTreeFromVector(inputVector);
    int expected = 6;
    Solution s;

    //run
    int actual = s.maxPathSum(inputNode);

    EXPECT_EQ(actual, expected);
}

TEST(Binary_Tree_Maximum_Path_Sum, general_case_2)
{
    // arrange
    vector<int> inputVector {-10, 9, 20, INT32_MIN, INT32_MIN, 15, 7};
    TreeNode* inputNode = generateTreeFromVector(inputVector);
    int expected = 42;
    Solution s;

    //run
    int actual = s.maxPathSum(inputNode);

    EXPECT_EQ(actual, expected);
}

TEST(Binary_Tree_Maximum_Path_Sum, max_is_individual_node)
{
    // arrange
    vector<int> inputVector {1, -2, INT32_MIN, 1, 3};
    TreeNode* inputNode = generateTreeFromVector(inputVector);
    int expected = 3;
    Solution s;

    //run
    int actual = s.maxPathSum(inputNode);

    EXPECT_EQ(actual, expected);
}

TEST(Binary_Tree_Maximum_Path_Sum_2, general_case)
{
    // arrange
    vector<int> inputVector {1, 2, 3};
    TreeNode* inputNode = generateTreeFromVector(inputVector);
    int expected = 6;
    Solution s;

    //run
    int actual = s.maxPathSum2(inputNode);

    EXPECT_EQ(actual, expected);
}

TEST(Binary_Tree_Maximum_Path_Sum_2, general_case_2)
{
    // arrange
    vector<int> inputVector {-10, 9, 20, INT32_MIN, INT32_MIN, 15, 7};
    TreeNode* inputNode = generateTreeFromVector(inputVector);
    int expected = 42;
    Solution s;

    //run
    int actual = s.maxPathSum2(inputNode);

    EXPECT_EQ(actual, expected);
}

TEST(Binary_Tree_Maximum_Path_Sum_2, max_is_individual_node)
{
    // arrange
    vector<int> inputVector {1, -2, INT32_MIN, 1, 3};
    TreeNode* inputNode = generateTreeFromVector(inputVector);
    int expected = 3;
    Solution s;

    //run
    int actual = s.maxPathSum2(inputNode);

    EXPECT_EQ(actual, expected);
}