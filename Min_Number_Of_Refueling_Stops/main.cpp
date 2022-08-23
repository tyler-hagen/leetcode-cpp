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

TEST(Min_Number_Of_Refueling_Stops, general_case)
{
    vector<vector<int>> stations = {{10,60},{20,30},{30,30},{60,40}};
    int target = 100;
    int startFuel = 10;
    Solution s;
    int expected = 2;

    int actual = s.minRefuelStops(target, startFuel, stations);
    EXPECT_EQ(actual, expected);
}

TEST(Min_Number_Of_Refueling_Stops, negative_case)
{
    vector<vector<int>> stations = {{10,100}};
    int target = 100;
    int startFuel = 1;
    Solution s;
    int expected = -1;

    int actual = s.minRefuelStops(target, startFuel, stations);
    EXPECT_EQ(actual, expected);
}

TEST(Min_Number_Of_Refueling_Stops, empty_case)
{
    vector<vector<int>> stations = {};
    int target = 1;
    int startFuel = 1;
    Solution s;
    int expected = 0;

    int actual = s.minRefuelStops(target, startFuel, stations);
    EXPECT_EQ(actual, expected);
}