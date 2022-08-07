#include <deque>
#include <queue>
using namespace std;

class Solution {
public:

    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        return kthSmallestMinHeap(matrix, k);
    }

    static bool pairOrder(std::pair<int, int> a, std::pair<int,int> b)
    {
        return a.first > b.first;
    }

    struct PairComparator
    {
        bool operator()(std::pair<int,int> a, std::pair<int,int> b)
        {
            return a.first > b.first;
        }
    };

    int kthSmallestMinHeap(vector<vector<int>>& matrix, int k) {

        bool (*p)(std::pair<int, int>, std::pair<int, int>);
        priority_queue<std::pair<int, int>, deque<std::pair<int, int>>, PairComparator> pq;
        vector<int> rowPositions(matrix.size(), 0);

        // initially populate queue with values from the first column
        for(auto i = 0; i < matrix.size(); i++)
        {
            pq.push(std::pair<int,int>(matrix[i][0], i));
        }

        while(k > 1)
        {
            auto i = pq.top(); pq.pop();
            if(++rowPositions[i.second] < matrix[i.second].size())
            {
                pq.push({matrix[i.second][rowPositions[i.second]], i.second});
            }
            k--;
        }

        return pq.top().first; 
    }

    int kthSmallestRecursive(const vector<vector<int>>& matrix, int k, int minRow, int minCol, int maxRow, int maxCol)
    {
        int midRow = minRow + (maxRow - minRow) / 2;
        int midCol = minCol + (maxCol - minCol) / 2;

        if(countMatrixElementsLessThan(matrix, midRow, midCol) < k - 1)
        {
            kthSmallestRecursive(matrix, k, midRow + 1, )
        }
    } 

    int countMatrixElementsLessThan(const vector<vector<int>>& matrix, int row, int column)
    {
        int guaranteedLessThan = (row + 1) * (column + 1) - 1;

        int topRightSquareRowIter = 0;
        int topRightSquareColIter = column + 1;

        int sum = 0;
        while(topRightSquareRowIter < row)
        {
            int colIter = topRightSquareColIter;
            while(colIter < matrix[topRightSquareRowIter].size())
            {
                if(matrix[topRightSquareRowIter][colIter] < matrix[row][column])
                {
                    sum++;
                    colIter++;
                }
                else
                    break;
            }
            topRightSquareRowIter++;
        }

        int bottomLeftSquareRowIter = row + 1;
        int bottomLeftSquareColIter = 0;

        while(bottomLeftSquareRowIter < matrix.size())
        {
            int colIter = 0;
            while(colIter < column)
            {
                if(matrix[bottomLeftSquareRowIter][colIter] < matrix[row][column])
                {
                    sum++;
                    colIter++;
                }
                else
                    break;
            }
            bottomLeftSquareRowIter++;
        }
    }
};


/*

1  1  5  9  x
11 12 13 14 x
12 18 19 22 x 
x  x  x  x  x
x  x  x  x  x
*/


/*

1  5  9 
10 11 14
12 13 15

*/