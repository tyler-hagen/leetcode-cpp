#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node();
    Node(int);
    Node(int, std::vector<Node*>);
    static Node* generateGraphFromAdjacencyList(const std::vector<std::vector<int>>&);
    static std::vector<std::vector<int>> generateAdjacencyListFromGraph(Node*);
};