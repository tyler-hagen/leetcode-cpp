#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(Add_And_Search_Words, general_case)
{
    // arrange
    WordDictionary wordDict;

    //run
    wordDict.addWord("bad");
    wordDict.addWord("dad");
    wordDict.addWord("mad");

    //assert
    EXPECT_FALSE(wordDict.search("pad"));
    EXPECT_TRUE(wordDict.search("bad"));
    EXPECT_TRUE(wordDict.search(".ad"));
    EXPECT_TRUE(wordDict.search("b.."));
    EXPECT_TRUE(wordDict.search("..."));
}