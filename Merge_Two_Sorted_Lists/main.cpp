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

TEST(Merge_Two_Sorted_Lists, general_case)
{
    // arrange
    vector<int> list1 = {1, 2, 4};
    vector<int> list2 = {1, 3, 4};
    vector<int> expected = {1, 1, 2, 3, 4, 4};
    ListNode* list1Tree = generateListFromVector(list1);
    ListNode* list2Tree = generateListFromVector(list2);
    ListNode* listExpected = generateListFromVector(expected);

    Solution sol;

    //run
    auto listActual = sol.mergeTwoLists(list1Tree, list2Tree);

    EXPECT_TRUE(*listActual == *listExpected);
}

TEST(Merge_Two_Sorted_Lists, empty_case)
{
    // arrange
    vector<int> list1 = {};
    vector<int> list2 = {};
    vector<int> expected = {};
    ListNode* list1Tree = generateListFromVector(list1);
    ListNode* list2Tree = generateListFromVector(list2);
    ListNode* listExpected = generateListFromVector(expected);

    Solution sol;

    //run
    auto listActual = sol.mergeTwoLists(list1Tree, list2Tree);

    EXPECT_EQ(listActual, nullptr);
}

TEST(Merge_Two_Sorted_Lists, one_list_empty)
{
    // arrange
    vector<int> list1 = {};
    vector<int> list2 = {0};
    vector<int> expected = {0};
    ListNode* list1Tree = generateListFromVector(list1);
    ListNode* list2Tree = generateListFromVector(list2);
    ListNode* listExpected = generateListFromVector(expected);

    Solution sol;

    //run
    auto listActual = sol.mergeTwoLists(list1Tree, list2Tree);

    EXPECT_TRUE(*listActual == *listExpected);
}