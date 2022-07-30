#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        // precalculate 1 hashmap that has that total num of chars required
        // from all strings in words2
        // o(n) where n is just the num of chars in words2
        unordered_map<char,int> requiredChars;
        
        for(auto i = words2.begin(); i != words2.end(); i++)
        {
            unordered_map<char,int> thisWordsChars;
            for(auto c = i->begin(); c != i->end(); c++)
            {
                if(++thisWordsChars[*c] > requiredChars[*c])
                    requiredChars[*c] = thisWordsChars[*c];
            }
        }
        
        vector<string> ret;      
        
        for(auto i = words1.begin(); i != words1.end(); i++)
        {
            unordered_map<char, int> thisWordsChars;
            for(auto c = i->begin(); c != i->end(); c++)
            {
                thisWordsChars[*c]++;
            }

            bool allCharsSatisfied = true;
            for(auto requiredCharsIter = requiredChars.begin(); requiredCharsIter != requiredChars.end(); requiredCharsIter++)
            {
                if(thisWordsChars[requiredCharsIter->first] < requiredCharsIter->second)
                {
                    allCharsSatisfied = false;
                    break;
                }
            }

            if(allCharsSatisfied)
                ret.push_back(*i);
        }

        return ret;
    }
};