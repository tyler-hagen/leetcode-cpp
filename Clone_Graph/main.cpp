#include <vector>
#include <iostream>
#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(Clone_Graph, general_case)
{
    // arrange
    vector<vector<int>> adjacencyList = {{2,4},{1,3},{2,4},{1,3}};
    Node* inputGraph = generateGraphFromAdjacencyList(adjacencyList);
    Solution sol;

    // run
    Node* actual = sol.cloneGraph(inputGraph);

    // assert
    EXPECT_TRUE(*actual == *inputGraph);
}