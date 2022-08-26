
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ret;
        Direction direction = RIGHT;
        int i = 0, j = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        ret.push_back(matrix[0][0]);
        matrix[0][0] = INT_MIN;

        if(cols < 2)
            direction = DOWN;
        while(direction != FINISHED)
        {
            switch(direction)
            {
                case RIGHT:
                    if(j+1 >= cols || matrix[i][j+1] == INT_MIN)
                        direction = FINISHED;
                    else
                    {
                        while(j+1 < cols && matrix[i][j+1] != INT_MIN)
                        {
                            ret.push_back(matrix[i][j+1]);
                            matrix[i][j+1] = INT_MIN;
                            j++;
                        }
                        direction = DOWN;
                    }
                    break;
                case DOWN:
                    if(i+1 >= rows || matrix[i+1][j] == INT_MIN)
                        direction = FINISHED;
                    else
                    {
                        while(i+1 < rows && matrix[i+1][j] != INT_MIN)
                        {
                            ret.push_back(matrix[i+1][j]);
                            matrix[i+1][j] = INT_MIN;
                            i++;
                        }
                        direction = LEFT;
                    }
                    break;
                case LEFT:
                    if(j-1 < 0 || matrix[i][j-1] == INT_MIN)
                        direction = FINISHED;
                    else
                    {
                        while(j-1 >= 0 && matrix[i][j-1] != INT_MIN)
                        {
                            ret.push_back(matrix[i][j-1]);
                            matrix[i][j-1] = INT_MIN;
                            j--;
                        }
                        direction = UP;
                    }
                    break;
                case UP:
                    if(i-1 < 0 || matrix[i-1][j] == INT_MIN)
                        direction = FINISHED;
                    else
                    {
                        while(i-1 >= 0 && matrix[i-1][j] != INT_MIN)
                        {
                            ret.push_back(matrix[i-1][j]);
                            matrix[i-1][j] = INT_MIN;
                            i--;
                        }
                        direction = RIGHT;
                    }
                    break;
                default:
                    break;
            }
        }

        return ret;
    }
private:
    enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        FINISHED
    }; 
};