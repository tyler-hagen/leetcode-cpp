#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int max = 0;
        int i = 0;
        int j = 0;
        unordered_map<char, int> occurences;

        occurences[s[0]]++;
        while(j != s.size())
        {
            int maxOccurences = -1;
            for(auto i = occurences.begin(); i != occurences.end(); i++)
                if(i->second > maxOccurences)
                    maxOccurences = i->second;

            if(j - i + 1 - maxOccurences <= k)
            {
                max = j - i + 1 > max ? j - i + 1 : max;
                occurences[s[++j]]++;
            }
            else
                occurences[s[i++]]--;
        }

        return max;
    }
};
