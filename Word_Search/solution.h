#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_set<char> charactersOnBoard;
        
        for(auto i = 0; i < board.size(); i++)
        {
            for(auto j = 0; j < board[i].size(); j++)
            {
                charactersOnBoard.insert(board[i][j]);
            }
        }

        for(char i : word)
        {
            if(charactersOnBoard.find(i) == charactersOnBoard.end())
                return false;
        }

        return findWord(board, word);
    }

    bool findWord(const vector<vector<char>>& board, const string& word)
    {
        vector<vector<bool>> alreadyVisited(board.size());
        for(auto i = 0; i < board.size(); i++)
        {
            for(auto j = 0; j < board[i].size(); j++)
            {
                alreadyVisited[i].push_back(false);
            }
        }

        for(auto i = 0; i < board.size(); i++)
        {
            for(auto j = 0; j < board[i].size(); j++)
            {
                if(traceWord(board, word, i, j, 0, alreadyVisited))
                    return true;
            }
        }

        return false;
    }

    bool traceWord(const vector<vector<char>>& board, const string& word, int row, int column, int idx, vector<vector<bool>>& alreadyVisited)
    {
        // not included in the alreadyVisited in this case
        if(
            row < 0 || row >= board.size() || column < 0 || column >= board[row].size() ||
            alreadyVisited[row][column] || 
            board[row][column] != word[idx]
        )
            return false;

        if(idx == word.size() - 1)
            return true;

        alreadyVisited[row][column] = true;

        bool ret = 
            traceWord(board, word, row + 1, column, idx + 1, alreadyVisited) || 
            traceWord(board, word, row - 1, column, idx + 1, alreadyVisited) || 
            traceWord(board, word, row, column + 1, idx + 1, alreadyVisited) || 
            traceWord(board, word, row, column - 1, idx + 1, alreadyVisited);

        alreadyVisited[row][column] = false;
        return ret;
    }
};