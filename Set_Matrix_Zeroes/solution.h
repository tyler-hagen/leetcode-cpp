
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // save if oringinally there was a zero in the row,col were using as a marker!
        bool firstRowShouldZeroOut = false, firstColShouldZeroOut = false;
        for(auto i = 0; i < cols; i++)
        {
            if(matrix[0][i] == 0)
                firstRowShouldZeroOut = true;
        }
        for(auto i = 0; i < rows; i++)
        {
            if(matrix[i][0] == 0)
                firstColShouldZeroOut = true;
        }
        
        for(auto i = 0; i < rows; i++)
        {
            for(auto j = 0; j < cols; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(auto i = 1; i < rows; i++)
        {
            if(matrix[i][0] == 0)
            {
                for(auto j = 1; j < cols; j++)
                {
                    matrix[i][j] = 0;
                }   
            }
        }

        for(auto i = 1; i < cols; i++)
        {
            if(matrix[0][i] == 0)
            {
                for(auto j = 1; j < rows; j++)
                {
                    matrix[j][i] = 0;
                }   
            }
        }

        if(firstRowShouldZeroOut)
        {
            for(auto i = 0; i < cols; i++)
            {
                matrix[0][i] = 0;
            }
        }

        if(firstColShouldZeroOut)
        {
            for(auto i = 0; i < rows; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};


//1 2 3 target = 4 expected = 7