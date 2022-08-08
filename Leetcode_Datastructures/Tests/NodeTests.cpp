#include <vector>
#include "gtest/gtest.h"

#include "../Node.h"

using namespace std;

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(Node_generateGraphFromAdjacencyList, general_case)
{
    // arrange
    vector<vector<int>> adjacencyList = {{2}, {1}};
    Node* inputGraph = Node::generateGraphFromAdjacencyList(adjacencyList);

    // run

    Node* actualRoot = new Node(2);

    // assert
    //EXPECT_TRUE(*actualRoot == *inputGraph);
}