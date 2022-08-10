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

TEST(Course_Schedule, general_case)
{
    vector<vector<int>> preReqs = {{1,0}};
    int numCourses = 2;
    Solution s;

    EXPECT_TRUE(s.canFinish(numCourses, preReqs));
}

TEST(Course_Schedule, general_case_2)
{
    vector<vector<int>> preReqs = {{1,0}, {0,1}};
    int numCourses = 2;
    Solution s;

    EXPECT_FALSE(s.canFinish(numCourses, preReqs));
}

TEST(Course_Schedule, general_case_3)
{
    vector<vector<int>> preReqs = {{0,1}};
    int numCourses = 2;
    Solution s;

    EXPECT_TRUE(s.canFinish(numCourses, preReqs));
}

TEST(Course_Schedule, general_case_4)
{
    vector<vector<int>> preReqs = {{1,4},{2,4},{3,1},{3,2}};
    int numCourses = 5;
    Solution s;

    EXPECT_TRUE(s.canFinish(numCourses, preReqs));
}