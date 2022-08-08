#include "Node.h"
#include <unordered_map>
#include <queue>

//REMOVE
#include <iostream>

Node::Node() 
{
    val = 0;
    neighbors = std::vector<Node*>();
}

Node::Node(int _val) 
{
    val = _val;
    neighbors = std::vector<Node*>();
}

Node::Node(int _val, std::vector<Node*> _neighbors) 
{
    val = _val;
    neighbors = _neighbors;
}

std::vector<std::vector<int>> Node::generateAdjacencyListFromGraph(Node* node)
{
    std::vector<std::vector<int>> adjacencyList;

    std::queue<Node*> pendingNeighbors;
    pendingNeighbors.push(node);
    while(!pendingNeighbors.empty())
    {
        auto thisNode = pendingNeighbors.front(); pendingNeighbors.pop();
        if(thisNode->val > adjacencyList.size())
        {

        }
        else if(adjacencyList[thisNode->val - 1].size() == 0)
        {

        }
    }

    return adjacencyList;
}

Node* Node::generateGraphFromAdjacencyList(const std::vector<std::vector<int>>& adjacencyList)
{
    if(adjacencyList.empty())
        return nullptr;

    Node* root = new Node;
    std::unordered_map<int, Node*> nodes;
    for(auto i = 0; i < adjacencyList.size(); i++)
    {
        Node* iter;
        if(nodes.find(i + 1) == nodes.end())
        {
            iter = new Node(i + 1);
            nodes[i + 1] = iter;
        }
        else
            iter = nodes[i+1];
        
        for(auto j = adjacencyList[i].begin(); j != adjacencyList[i].end(); j++)
        {
            if(nodes.find(*j) == nodes.end())
            {
                Node* createNeighborNode = new Node(*j);
                iter->neighbors.push_back(createNeighborNode);
                nodes[*j] = createNeighborNode;
            }
            else
            {
                Node* neighborNode = nodes.find(*j)->second;
                iter->neighbors.push_back(neighborNode);
            }
        }
    }

    return root;
}