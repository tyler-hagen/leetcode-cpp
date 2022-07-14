#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(Implement_Trie, general_case)
{
    // arrange
    Trie trie;

    //run
    trie.insert("apple");

    //assert
    EXPECT_TRUE(trie.search("apple"));   // return True
    EXPECT_FALSE(trie.search("app"));     // return False
    EXPECT_TRUE(trie.startsWith("app")); // return True
}