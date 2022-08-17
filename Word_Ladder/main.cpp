#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(Word_Ladder, general_case)
{
    // arrange
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution s;
    int expected = 5;

    //run
    auto actual = s.ladderLength(beginWord, endWord, wordList);
    
    //assert
    EXPECT_EQ(actual, expected);
}

TEST(Word_Ladder, none_case)
{
    // arrange
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log"};
    Solution s;
    int expected = 0;

    //run
    auto actual = s.ladderLength(beginWord, endWord, wordList);
    
    //assert
    EXPECT_EQ(actual, expected);
}

TEST(Word_Ladder_IsOneOff, general_case)
{
    // arrange
    string left = "hit";
    string right = "hot";
    Solution s;

    //run
    auto actual = s.IsOneOff(left, right);
    
    //assert
    EXPECT_TRUE(actual);
}