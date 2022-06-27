#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ret = -1;
        unordered_map<char, int> earliestIndices;
        for(auto i = s.begin(); i != s.end(); i++)
        {
            int idx = std::distance(s.begin(), i);
            auto earliestIndexItr = earliestIndices.find(*i); 
            if(earliestIndexItr != earliestIndices.end())
            {
                int earliestIndex = earliestIndexItr->second;
                int distBetween = idx - earliestIndex - 1;
                if(distBetween > ret)
                    ret = distBetween;
            }
            else
            {
                earliestIndices.emplace(*i, idx);
            }
        }

        return ret;
    }
};

