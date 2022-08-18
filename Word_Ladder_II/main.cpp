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
    vector<vector<string>> expected = {{"hit","hot","lot","log","cog"},{"hit","hot","dot","dog","cog"}};

    //run
    auto actual = s.findLadders(beginWord, endWord, wordList);
    
    //assert
    EXPECT_EQ(actual, expected);
}

TEST(Word_Ladder, empty_case)
{
    // arrange
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log"};
    Solution s;
    vector<vector<string>> expected;

    //run
    auto actual = s.findLadders(beginWord, endWord, wordList);
    
    //assert
    EXPECT_EQ(actual, expected);
}