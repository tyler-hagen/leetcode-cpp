#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:

    unordered_map<string, unordered_set<string>> wildCards;

    Solution(): wildCards()
    {

    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        // insert beginWord
        string copyBeginWord(beginWord);
        for(auto j = 0; j < copyBeginWord.length(); j++)
        {
            char temp = copyBeginWord[j];
            copyBeginWord[j] = '*';
            wildCards[copyBeginWord].insert(beginWord);
            copyBeginWord[j] = temp;
        }

        // O(n*m) ??
        for(auto i = wordList.begin(); i != wordList.end(); i++)
        {
            string key(*i);
            for(auto j = 0; j < i->length(); j++)
            {
                char temp = key[j];
                key[j] = '*';
                wildCards[key].insert(*i);
                key[j] = temp;
            }
        }
        
        unordered_set<string> visited;
        queue<pair<string,int>> wordsToVisit;
        wordsToVisit.emplace(beginWord,1);
        visited.insert(beginWord);
        while(!wordsToVisit.empty())
        {
            auto currentWord = wordsToVisit.front(); wordsToVisit.pop();
            for(auto j = 0; j < currentWord.first.length(); j++)
            {
                // this takes O(m) time where m is the length of each word (they are all the same length)
                string key(currentWord.first);
                key[j] = '*';
                for(auto i = wildCards.at(key).begin(); i != wildCards.at(key).end(); i++)
                {
                    if(*i == endWord)
                        return currentWord.second + 1;
                    if(visited.find(*i) == visited.end())
                    {
                        wordsToVisit.emplace(*i, currentWord.second + 1);
                        visited.insert(*i);
                    }
                }
            }
        }

        return 0;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        vector<vector<string>> ret;
        int minLadderLength = ladderLength(beginWord, endWord, wordList);

        if(minLadderLength == 0 )
            return ret;

        vector<string> thisLadder;
        unordered_set<string> inLadderAlready;
        dfs(endWord, beginWord, thisLadder, inLadderAlready, ret, minLadderLength);

        return ret;
    }

    void dfs(string beginWord, string endWord, vector<string>& thisLadder, unordered_set<string>& inLadderAlready, vector<vector<string>>& ret, const int depth)
    {
        thisLadder.push_back(beginWord);
        if(thisLadder.size() == depth)
        {
            if(beginWord == endWord)
            {
                ret.push_back(thisLadder);
                std::reverse(ret[ret.size() - 1].begin(), ret[ret.size() - 1].end());
            }
            thisLadder.pop_back();
            return;
        }

        inLadderAlready.insert(beginWord);
        for(auto i = beginWord.begin(); i != beginWord.end(); i++)
        {
            char temp = *i;
            *i = '*';
            for(auto j = wildCards.at(beginWord).begin(); j != wildCards.at(beginWord).end(); j++)
            {
                if(inLadderAlready.find(*j) == inLadderAlready.end())
                {
                    dfs(*j, endWord, thisLadder, inLadderAlready, ret, depth);
                }
            }
            *i = temp;
        }

        thisLadder.pop_back();
        inLadderAlready.erase(beginWord);
    } 
};