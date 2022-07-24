using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;

        while(!strs.empty())
        {
            ret.push_back({strs.back()});
            strs.erase(std::prev(strs.end()));

            auto& thisGroup = ret.back();

            auto i = strs.rbegin(); 
            while(i != strs.rend())
            {
                if(isAnagram(thisGroup.front(), *i))
                {
                    thisGroup.push_back(*i);
                    // this just erases element at reverse iterator i...
                    i = vector<string>::reverse_iterator(strs.erase(std::next(i).base()));
                }
                else
                    i++;
            }

        }
        
        return ret;
    }

    bool isAnagram(const string& s, const string& t) {
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