#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        unordered_map<string,int> allWords;
        for(auto i = words.begin(); i != words.end(); i++)
            allWords[*i]++;

        int wordsSize = words[0].size();
        for(int i = 0; i < s.size(); i++)
        {
            unordered_map<string,int> wordsInThisIter;
            for(int j = i; j < (s.size() - wordsSize + 1); j += wordsSize)
            {
                string thisWord = s.substr(j, wordsSize);
                if(allWords.find(thisWord) != allWords.end() && wordsInThisIter[thisWord] < allWords[thisWord])
                    wordsInThisIter[thisWord]++;
                else
                    break;
            }

            bool addThisIndex = true;
            if(wordsInThisIter.size() == allWords.size())
            {
                for(auto i = wordsInThisIter.begin(); i != wordsInThisIter.end(); i++)
                {   
                    if(allWords[i->first] != i->second)
                    {
                        addThisIndex = false;
                        break;
                    }
                }
            }
            else
            {
                addThisIndex = false;
            }

            if(addThisIndex)
                ret.push_back(i);
        }

        return ret;
    }
};