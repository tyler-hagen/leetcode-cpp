#include <vector>
#include "gtest/gtest.h"

#include "../ListNode.h"

using namespace std;

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(ListNode_Generate, general_case)
{
    // arrange
    vector<int> inputVec = {1, 2, 3};
    ListNode* expected = new ListNode(1, new ListNode(2, new ListNode(3)));

    // run

    ListNode* actual = ListNode::GenerateListNodeFromVector(inputVec);

    // assert
    EXPECT_TRUE(*actual == *expected);
}

TEST(ListNode_Generate, null_case)
{
    // arrange
    vector<int> inputVec = {};

    // run

    ListNode* actual = ListNode::GenerateListNodeFromVector(inputVec);

    // assert
    EXPECT_TRUE(actual == nullptr);
}

TEST(ListNode_Generate, one_element)
{
    // arrange
    vector<int> inputVec = {1};
    ListNode* expected = new ListNode(1);

    // run

    ListNode* actual = ListNode::GenerateListNodeFromVector(inputVec);

    // assert
    EXPECT_TRUE(*actual == *expected);
}

TEST(ListNode_Generate, repeat_element)
{
    // arrange
    vector<int> inputVec = {7,7,7};
    ListNode* expected = new ListNode(7, new ListNode(7, new ListNode(7)));

    // run

    ListNode* actual = ListNode::GenerateListNodeFromVector(inputVec);

    // assert
    EXPECT_TRUE(*actual == *expected);
}

TEST(ListNode_Generate, false_case)
{
    // arrange
    vector<int> inputVec = {7,7,7};
    ListNode* expected = new ListNode(7, new ListNode(7, new ListNode(1)));

    // run

    ListNode* actual = ListNode::GenerateListNodeFromVector(inputVec);

    // assert
    EXPECT_FALSE(*actual == *expected);
}