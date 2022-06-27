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

TEST(Same_Tree, simple_true_case)
{
    // arrange
    vector<int> inputVector = {1, 2, 3};
    TreeNode* inputNodeP = generateTreeFromVector(inputVector);
    TreeNode* inputNodeQ = generateTreeFromVector(inputVector);
    Solution s;

    //run
    bool isSame = s.isSameTree(inputNodeP, inputNodeQ);

    EXPECT_TRUE(isSame);
}

TEST(Same_Tree, empty_tree_case)
{
    // arrange
    vector<int> inputVectorP = {1, 2};
    vector<int> inputVectorQ = {1, INT32_MIN, 2};
    TreeNode* inputNodeP = generateTreeFromVector(inputVectorP);
    TreeNode* inputNodeQ = generateTreeFromVector(inputVectorQ);
    Solution s;

    //run
    bool isSame = s.isSameTree(inputNodeP, inputNodeQ);

    EXPECT_FALSE(isSame);
}

TEST(Same_Tree, false_case)
{
    // arrange
    vector<int> inputVectorP = {1, 2, 1};
    vector<int> inputVectorQ = {1, 1, 2};
    TreeNode* inputNodeP = generateTreeFromVector(inputVectorP);
    TreeNode* inputNodeQ = generateTreeFromVector(inputVectorQ);
    Solution s;

    //run
    bool isSame = s.isSameTree(inputNodeP, inputNodeQ);

    EXPECT_FALSE(isSame);
}