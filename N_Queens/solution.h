#include <unordered_set>
using namespace std;

class Solution {
public:

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ret;
        unordered_set<int> cols;
        unordered_set<int> posDiags;
        unordered_set<int> negDiags;
        vector<string> thisBoard;
        
        solveNQueens(ret, thisBoard, n, cols, posDiags, negDiags);

        return ret;
    }

    void solveNQueens(vector<vector<string>>& boards, vector<string>& thisBoard, int n, unordered_set<int>& cols, unordered_set<int>& posDiags, unordered_set<int>& negDiags)
    {

        if(thisBoard.size() == n)
        {
            boards.push_back(thisBoard);
        }

        // which row we're currently on
        int rowNum = thisBoard.size();

        for(int i = 0; i < n; i++)
        {
            int posDiagVal = rowNum - i;
            int negDiagVal = rowNum + i;
            // this position (rowNum, i) is not blocked by a current queen
            if(cols.find(i) == cols.end() 
                && posDiags.find(posDiagVal) == posDiags.end()
                && negDiags.find(negDiagVal) == negDiags.end())
            {
                cols.insert(i);
                posDiags.insert(posDiagVal);
                negDiags.insert(negDiagVal);
                thisBoard.emplace_back(n, '.');
                thisBoard[thisBoard.size() - 1][i] = 'Q'; 
                solveNQueens(boards, thisBoard, n, cols, posDiags, negDiags);
                cols.erase(i);
                posDiags.erase(posDiagVal);
                negDiags.erase(negDiagVal);
                thisBoard.pop_back();
            }
        }

        return;
    }
};