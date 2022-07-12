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

TEST(BT_From_Preorder_Inorder, general_case)
{
    // arrange
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* expected = generateTreeFromVector({3,9,20,INT32_MIN,INT32_MIN,15,7});
    Solution s;

    //run
    auto actual = s.buildTree(preorder, inorder);

    EXPECT_TRUE(*actual == *expected);
}