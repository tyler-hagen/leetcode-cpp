#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        // O(n) time, O(n) space
        unordered_map<int, int> occurences;
        for(auto i = arr.begin(); i != arr.end(); i++)
        {
            occurences[*i]++;
        }

        priority_queue<int> occurenceValsOnly;
        for(auto i = occurences.begin(); i != occurences.end(); i++)
        {
            occurenceValsOnly.push(i->second);
        }

        int numsRemovedFromSet = 0;
        int totalRemoved = 0; 
        while(totalRemoved < arr.size() / 2)
        {
            totalRemoved += occurenceValsOnly.top(); occurenceValsOnly.pop();
            numsRemovedFromSet++;
        }

        return numsRemovedFromSet;
    }
};