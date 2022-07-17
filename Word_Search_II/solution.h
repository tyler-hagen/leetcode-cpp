#include <string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;

        for(auto i = words.begin(); i != words.end(); i++)
        {
            if(findWord(board, *i))
                ret.push_back(*i);
        }

        return ret;
    }

    bool findWord(const vector<vector<char>>& board, const string& word)
    {
        bool wordFound = false;
        //first, find coords of every occurence of the first letter
        vector<int> row;
        vector<int> column;
        findAllOccurences(board, word[0], row, column);
        vector<vector<bool>> alreadyVisited(board.size());
        for(auto i = 0; i < board.size(); i++)
        {
            for(auto j = 0; j < board[i].size(); j++)
            {
                alreadyVisited[i].push_back(false);
            }
        }

        for(auto i = 0; i < row.size(); i++)
        {
            if(traceWord(board, word, row[i], column[i], 0, alreadyVisited))
                return true;
        }

        return false;
    }

    bool traceWord(const vector<vector<char>>& board, const string& word, int row, int column, int idx, vector<vector<bool>>& alreadyVisited)
    {
        // not included in the alreadyVisited in this case
        if(board[row][column] != word[idx])
            return false;

        if(idx == word.size() - 1)
            return true;

        alreadyVisited[row][column] = true;
        vector<int> rows;
        vector<int> columns;
        findAdjacents(board, alreadyVisited, row, column, rows, columns);

        bool ret = false;
        for(int i = 0; i < rows.size(); i++)
        {
            if(traceWord(board, word, rows[i], columns[i], idx + 1, alreadyVisited))
                ret = true;
        }
        alreadyVisited[row][column] = false;
        return ret;
    }

    void findAdjacents(const vector<vector<char>>& board, const vector<vector<bool>>& alreadyVisited, const int row, const int column, vector<int>& rows, vector<int>& columns)
    {
        if(row - 1 >= 0 && !alreadyVisited[row - 1][column])
        {
            rows.push_back(row - 1);
            columns.push_back(column);
        }
        if(row + 1 < board.size() && !alreadyVisited[row + 1][column])
        {
            rows.push_back(row + 1);
            columns.push_back(column);
        }
        if(column - 1 >= 0 && !alreadyVisited[row][column - 1])
        {
            rows.push_back(row);
            columns.push_back(column - 1);
        }
        if(column + 1 < board[row].size() && !alreadyVisited[row][column + 1])
        {
            rows.push_back(row);
            columns.push_back(column + 1);
        }

        return;
    }

    void findAllOccurences(const vector<vector<char>>& board, char c, vector<int>& row, vector<int>& column)
    {
        for(auto i = board.begin(); i != board.end(); i++)
        for(auto j = i->begin(); j != i->end(); j++)
        {
            if(*j == c)
            {
                row.push_back(std::distance(board.begin(), i));
                column.push_back(std::distance(i->begin(), j));
            }
        }

        return;
    }
};