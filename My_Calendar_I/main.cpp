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

TEST(My_Calendar_I, general_case)
{
    MyCalendar s;

    EXPECT_TRUE(s.book(10,20));
    EXPECT_FALSE(s.book(15,25));
    EXPECT_TRUE(s.book(20,30));
}