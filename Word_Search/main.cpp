#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(Word_Search, general_case)
{
    // arrange
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    Solution s;

    //run
    auto actual = s.exist(board, word);
    
    //assert
    EXPECT_TRUE(actual);
}

TEST(Word_Search, general_case_2)
{
    // arrange
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "SEE";
    Solution s;

    //run
    auto actual = s.exist(board, word);
    
    //assert
    EXPECT_TRUE(actual);
}

TEST(Word_Search, false_case)
{
    // arrange
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCB";
    Solution s;

    //run
    auto actual = s.exist(board, word);
    
    //assert
    EXPECT_FALSE(actual);
}