
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        vector<vector<bool>> canAccessPacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> canAccessAtlantic(heights.size(), vector<bool>(heights[0].size(), false));

        for(auto i = 0; i < heights[0].size(); i++)
        {
            dfs(0, i, heights[0][i], canAccessPacific, heights);
            dfs(heights.size() - 1, i, heights[heights.size() - 1][i], canAccessAtlantic, heights);
        }

        for(auto i = 0; i < heights.size(); i++)
        {
            dfs(i, 0, heights[i][0], canAccessPacific, heights);
            dfs(i, heights[0].size() - 1, heights[i][heights[0].size() - 1], canAccessAtlantic, heights);
        }

        vector<vector<int>> ret;
        for(int i = 0; i < heights.size(); i++)
        for(int j = 0; j < heights[0].size(); j++)
        {
            if(canAccessAtlantic[i][j] && canAccessPacific[i][j])
                ret.push_back({i,j});
        }

        return ret;        
    }

    void dfs(int row, int col, int prevHeight, vector<vector<bool>>& canAccessAlready, const vector<vector<int>>& heights)
    {
        if(row < 0 || col < 0 || row >= heights.size() || col >= heights[0].size()
           || canAccessAlready[row][col]
           || heights[row][col] < prevHeight)
           return;
        canAccessAlready[row][col] = true;
        dfs(row+1, col, heights[row][col], canAccessAlready, heights);
        dfs(row-1, col, heights[row][col], canAccessAlready, heights);
        dfs(row, col-1, heights[row][col], canAccessAlready, heights);
        dfs(row, col+1, heights[row][col], canAccessAlready, heights);
    }

};