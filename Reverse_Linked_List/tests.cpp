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

TEST(Reverse_Linked_List, general_case)
{
    auto head = new ListNode(3);

    auto node = head;
    for(auto i = 0; i < 5; i++)
    {
        node->next = new ListNode(i + 1);
        node = node->next;
    }

    Solution s;
    auto retList = s.reverseList(head);

    EXPECT_EQ(retList->val, 5);
}
