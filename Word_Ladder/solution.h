#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution 
{
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_map<string, unordered_set<string>> wildCards;

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

    bool IsOneOff(const string& left, const string& right)
    {
        bool differentCharacterFound = false;
        for(string::const_iterator i = left.begin(), j = right.begin(); i != left.end() && j != right.end(); i++, j++)
        {
            // they are more than one off.
            if(*i != *j && differentCharacterFound)
                return false;
            else if(*i != *j)
                differentCharacterFound = true;
        }

        return differentCharacterFound;
    }
};