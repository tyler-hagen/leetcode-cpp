using namespace std;

class Solution {
public:
    
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> precalcVals; 
        for(auto i = 0; i < m; i++)
        {
            precalcVals.push_back(vector<int>());
            for(auto j = 0; j < n; j++)
                precalcVals[i].push_back(-1);
        }
        
        precalcVals[0][0] = 1;
        
        return uniquePaths(m-1, n-1, precalcVals);
    }
    
    int uniquePaths(int m, int n, vector<vector<int>>& precalc)
    {
        if(m < 0 || n < 0)
            return 0;
        if(precalc[m][n] != -1)
            return precalc[m][n];
        
        precalc[m][n] = uniquePaths(m - 1, n, precalc) + uniquePaths(m, n - 1, precalc);
        return precalc[m][n];
    }
};