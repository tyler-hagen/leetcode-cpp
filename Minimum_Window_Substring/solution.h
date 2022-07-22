#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> sOccurences;
        unordered_map<char, int> tOccurences;

        for(auto i = t.begin(); i != t.end(); i++)
            tOccurences[*i]++;

        const int need = tOccurences.size();
        int have = 0;
        int minWindowSubstrI= 0; 
        int minWindowSubstrJ = s.size();

        int i = 0;
        int j = 0;
        while(j != s.size())
        {
            if(++sOccurences[s[j]] == tOccurences[s[j]])
                have++;
            
            
            while(have == need)
            {
                if(j - i < minWindowSubstrJ - minWindowSubstrI)
                {
                    minWindowSubstrI = i;
                    minWindowSubstrJ = j;
                }

                if(--sOccurences[s[i]] < tOccurences[s[i]])
                    have--;
                i++;
            }


            j++;
        }

        // we never found a valid substr
        if(minWindowSubstrJ == s.size())
            return "";
        
        return s.substr(minWindowSubstrI, minWindowSubstrJ - minWindowSubstrI + 1);
    }
};
