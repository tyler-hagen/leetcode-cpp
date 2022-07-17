#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(Word_Search_II, general_case)
{
    // arrange
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    Solution s;
    vector<string> expected = {"oath", "eat"};

    //run
    auto actual = s.findWords(board, words);
    
    //assert
    EXPECT_EQ(actual, expected);
}

TEST(Word_Search_II, one_row_two_columns)
{
    // arrange
    vector<vector<char>> board = {{'a','a'}};
    vector<string> words = {"aa"};
    Solution s;
    vector<string> expected = {"aa"};

    //run
    auto actual = s.findWords(board, words);
    
    //assert
    EXPECT_EQ(actual, expected);
}

TEST(Word_Search_II, one_column_two_rows)
{
    // arrange
    vector<vector<char>> board = {{'a'}, {'a'}};
    vector<string> words = {"aa"};
    Solution s;
    vector<string> expected = {"aa"};

    //run
    auto actual = s.findWords(board, words);
    
    //assert
    EXPECT_EQ(actual, expected);
}