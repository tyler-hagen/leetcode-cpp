#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // build adjacency list
        // reqCourse -> course
        vector<unordered_set<int>> adjList(numCourses);
        for(auto i = prerequisites.begin(); i != prerequisites.end(); i++)
        {
            adjList[i->at(1)].insert(i->at(0));
        }   

        unordered_set<int> alreadyVisited;
        unordered_set<int> alreadyCalcdNoCycle;
        for(int i = 0; i < adjList.size(); i++)
        {
            if(cycleExists(adjList, alreadyCalcdNoCycle, alreadyVisited, i))
                return false;
        }

        return true;     
    }

    // checks if a cycle exists starting at this node in the graph
    bool cycleExists(const vector<unordered_set<int>>& adjList, unordered_set<int>& alreadyCalcdNoCycle, unordered_set<int>& alreadyVisited, int node)
    {
        if(alreadyCalcdNoCycle.find(node) != alreadyCalcdNoCycle.end())
            return false;

        if(alreadyVisited.find(node) != alreadyVisited.end())
            return true;

        alreadyVisited.insert(node);
        for(auto i = adjList[node].begin(); i != adjList[node].end(); i++)
        {
            if(cycleExists(adjList, alreadyCalcdNoCycle, alreadyVisited, *i))
                return true;
        }
        alreadyVisited.erase(node);
        alreadyCalcdNoCycle.insert(node);

        return false;
    }
};