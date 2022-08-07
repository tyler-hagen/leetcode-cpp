#include <vector>
#include <iostream>
#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

TEST(Kth_Smallest_Element_Sorted_Matrix, general_case)
{
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    int k = 8;
    Solution s;
    int expected = 13;

    int actual = s.kthSmallest(matrix, k);
    EXPECT_EQ(actual, expected);
}

TEST(Kth_Smallest_Element_Sorted_Matrix, one_negative_element)
{
    vector<vector<int>> matrix = {{-5}};
    int k = 1;
    Solution s;
    int expected = -5;

    int actual = s.kthSmallest(matrix, k);
    EXPECT_EQ(actual, expected);
}