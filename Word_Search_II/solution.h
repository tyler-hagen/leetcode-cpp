#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        vector<vector<bool>> alreadyVisited(board.size());
        unordered_set<char> charsOnBoard;
        for(auto i = 0; i < board.size(); i++)
        {
            for(auto j = 0; j < board[i].size(); j++)
            {
                alreadyVisited[i].push_back(false);
                charsOnBoard.insert(board[i][j]);
            }
        }

        auto i = words.begin();
        while(i != words.end())
        {
            bool allCharsExist = true;
            for(auto j = i->begin(); j != i->end(); j++)
            {
                if(charsOnBoard.find(*j) == charsOnBoard.end())
                {
                    i = words.erase(i);
                    allCharsExist = false;
                    break;
                }
            }
            // only increment if we didn't get back the new iterator from erase
            if(allCharsExist)
                i++;
        }

        Trie trie;
        for(auto i = words.begin(); i != words.end(); i++)
        {
            trie.insert(*i);
        }

        unordered_set<string> answerSet;
        string word = "";
        for(auto i = 0; i < board.size(); i++)
        for(auto j = 0; j < board[i].size(); j++)
        {
            if(answerSet.size() == words.size())
                break;
            trace(board, trie.root, alreadyVisited, answerSet, word, i, j);
        }

        vector<string> ret(answerSet.begin(), answerSet.end());

        return ret;
    }

private:

    class Trie {
        public:

            struct TrieNode
            {
                bool isTerminal = false;
                unordered_map<char, TrieNode*> nextChars;
            };
            TrieNode* root;

            Trie() {
                root = new TrieNode;
            }

            void insert(string word) {
                TrieNode* iterNode = root;
                for(auto i = word.begin(); i != word.end(); i++)
                {
                    if(iterNode->nextChars.find(*i) == iterNode->nextChars.end())
                    {
                        iterNode->nextChars[*i] = new TrieNode;
                    }
                    iterNode = iterNode->nextChars[*i];
                }
                
                iterNode->isTerminal = true;
                return;
            }
    };

    void trace(const vector<vector<char>>& board, Trie::TrieNode* trieNode, vector<vector<bool>>& alreadyVisited, unordered_set<string>& answerSet, string& word, int row, int column)
    {
        if(trieNode->isTerminal)
        {
            answerSet.insert(word);
        }
        if(
            row < 0 || row >= board.size() || column < 0 || column >= board[row].size() ||
            alreadyVisited[row][column] ||
            trieNode->nextChars.find(board[row][column]) == trieNode->nextChars.end()
        )
        {
            return;
        }

        word += board[row][column];
        alreadyVisited[row][column] = true;
        
        trace(board, trieNode->nextChars[board[row][column]], alreadyVisited, answerSet, word, row + 1, column);
        trace(board, trieNode->nextChars[board[row][column]], alreadyVisited, answerSet, word, row - 1, column);
        trace(board, trieNode->nextChars[board[row][column]], alreadyVisited, answerSet, word, row, column + 1);
        trace(board, trieNode->nextChars[board[row][column]], alreadyVisited, answerSet, word, row, column - 1);

        word.pop_back();
        alreadyVisited[row][column] = false;

        return;
    }
};