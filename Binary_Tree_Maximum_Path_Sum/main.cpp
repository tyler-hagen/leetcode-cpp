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