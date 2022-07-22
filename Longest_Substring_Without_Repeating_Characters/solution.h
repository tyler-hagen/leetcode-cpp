#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        unordered_map<char, int> set;

        int i = 0;
        int j = 0;
        while(j < s.size())
        {
            if(set.find(s[j]) != set.end())
            {
                max = max < j - i ? j - i : max;
                while(i < set[s[j]] + 1)
                    set.erase(s[i++]);
            }

            set[s[j]] = j;
            j++;
        }

        max = max < j - i ? j - i : max;

        return max;
    }
};
