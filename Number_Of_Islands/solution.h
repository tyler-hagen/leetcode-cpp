
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int sum = 0;

        for(auto i = 0; i < grid.size(); i++)
        for(auto j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == '1')
            {
                sum++;
                dfs(i, j, grid);
            }
        }

        return sum;
    }

    void dfs(int row, int col, vector<vector<char>>& grid)
    {
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] == '0')
            return;
        grid[row][col] = '0';
        dfs(row+1, col, grid);
        dfs(row-1, col, grid);
        dfs(row, col+1, grid);
        dfs(row, col-1, grid);

        return;
    }
};