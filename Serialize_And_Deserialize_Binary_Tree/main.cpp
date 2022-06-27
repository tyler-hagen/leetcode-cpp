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

TEST(Serialize_And_Deserialize_Binary_Tree, empty_tree_case)
{
    // arrange
    vector<int> inputVector;
    TreeNode* inputNode = generateTreeFromVector(inputVector);
    TreeNode* expected = nullptr;
    Codec s;

    //run
    auto serialized = s.serialize(inputNode);
    auto deserialized = s.deserialize(serialized);

    EXPECT_EQ(deserialized, expected);
}

TEST(Serialize_And_Deserialize_Binary_Tree, general_case)
{
    // arrange
    vector<int> inputVector = {1,2,3,INT32_MIN,INT32_MIN,4,5};
    TreeNode* inputNode = generateTreeFromVector(inputVector);
    Codec s;

    //run
    auto serialized = s.serialize(inputNode);
    auto deserialized = s.deserialize(serialized);

    EXPECT_EQ(*deserialized, *inputNode);
}