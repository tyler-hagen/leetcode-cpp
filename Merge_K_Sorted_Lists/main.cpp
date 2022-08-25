#include <vector>
#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(Merge_K_Sorted_Lists, general_case)
{
    // arrange
    vector<vector<int>> lists = {{1,4,5},{1,3,4},{2,6}};
    vector<ListNode*> inputLists;
    for(auto i = lists.begin(); i != lists.end(); i++)
    {
        inputLists.push_back(ListNode::GenerateListNodeFromVector(*i));
    }

    ListNode* expected = ListNode::GenerateListNodeFromVector({1,1,2,3,4,4,5,6});
    Solution sol;

    // run
    ListNode* actual = sol.mergeKLists(inputLists);

    // assert
    EXPECT_TRUE(*actual == *expected);
}

TEST(Merge_K_Sorted_Lists, empty_outer_vector)
{
    // arrange
    vector<vector<int>> lists = {};
    vector<ListNode*> inputLists;
    for(auto i = lists.begin(); i != lists.end(); i++)
    {
        inputLists.push_back(ListNode::GenerateListNodeFromVector(*i));
    }

    ListNode* expected = nullptr;
    Solution sol;

    // run
    ListNode* actual = sol.mergeKLists(inputLists);

    // assert
    EXPECT_TRUE(actual == nullptr);
}

TEST(Merge_K_Sorted_Lists, empty_inner_list)
{
    // arrange
    vector<vector<int>> lists = {{}};
    vector<ListNode*> inputLists;
    for(auto i = lists.begin(); i != lists.end(); i++)
    {
        inputLists.push_back(ListNode::GenerateListNodeFromVector(*i));
    }

    ListNode* expected = nullptr;
    Solution sol;

    // run
    ListNode* actual = sol.mergeKLists(inputLists);

    // assert
    EXPECT_TRUE(actual == nullptr);
}