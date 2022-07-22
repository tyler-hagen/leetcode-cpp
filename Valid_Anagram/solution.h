using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // prune
        if(s.size() != t.size())
            return false;

        // empty initializer actually sets all elements to 0. without this, they would be garbage (random)
        int schars[26] = {};
        int tchars[26]= {};

        for(auto i = 0; i < s.size(); i++)
        {
            schars[s[i] - 'a']++; 
        }

        for(auto i = 0; i < t.size(); i++)
        {
            if(++tchars[t[i] - 'a'] > schars[t[i] - 'a'])
                return false;
        }

        for(auto i = 0; i < 26; i++)
        {
            if(schars[i] != tchars[i])
                return false;
        } 

        return true;
    }
};
