#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    enum Flow
    {
        NOT_CALCD,
        NONE,
        PACIFIC,
        ATLANTIC,
        PACIFIC_AND_ATLANTIC
    };

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        vector<vector<Flow>> calcdFlows(heights.size());
        for(auto i = 0; i < heights.size(); i++)
        for(auto j = 0; j < heights[0].size(); j++)
        {
            calcdFlows[i].push_back(NOT_CALCD);
        }

        calcdFlows[0][heights[0].size() - 1] = PACIFIC_AND_ATLANTIC;
        calcdFlows[heights.size() - 1][0] = PACIFIC_AND_ATLANTIC; 


        vector<vector<bool>> visited(heights.size());
        for(auto i = 0; i < heights.size(); i++)
        for(auto j = 0; j < heights[0].size(); j++)
        {
            visited[i].push_back(false);
        }


        for(auto i = 0; i < heights.size(); i++)
        for(auto j = 0; j < heights[0].size(); j++)
        {
            calcdFlows[i][j] = pacificAtlantic(heights, i, j, visited, calcdFlows);
        }

        vector<vector<int>> ret;
        for(auto i = 0; i < calcdFlows.size(); i++)
        for(auto j = 0; j < calcdFlows[i].size(); j++)
        {
            if(calcdFlows[i][j] == PACIFIC_AND_ATLANTIC)
                ret.push_back({i,j});
        }

        return ret;
    }

    Flow pacificAtlantic(const vector<vector<int>>& heights, int row, int col, vector<vector<bool>>& visited, vector<vector<Flow>>& calcdFlows)
    {
        if(calcdFlows[row][col] != NOT_CALCD)
            return calcdFlows[row][col];

        vector<std::pair<int,int>> neighborSquares;
        neighborSquares.emplace_back(row-1, col);
        neighborSquares.emplace_back(row+1, col);
        neighborSquares.emplace_back(row, col-1);
        neighborSquares.emplace_back(row, col+1);

        Flow thisSquaresFlow = NONE;
        visited[row][col] = true;
        for(auto i = neighborSquares.begin(); i != neighborSquares.end(); i++)
        {
            if(i->first < 0 || i->second < 0)
            {
                if(thisSquaresFlow == ATLANTIC)
                    thisSquaresFlow = PACIFIC_AND_ATLANTIC;
                else
                    thisSquaresFlow = PACIFIC;
                continue;
            }
            if(i->first >= heights.size() || i->second >= heights[0].size())
            {
                if(thisSquaresFlow == PACIFIC)
                    thisSquaresFlow = PACIFIC_AND_ATLANTIC;
                else
                    thisSquaresFlow = ATLANTIC;
                continue;
            }

            // dont need to continue with other neighbors - we know we can get out to pacific and atlantic
            if(thisSquaresFlow == PACIFIC_AND_ATLANTIC)
                break;

            if(!visited[i->first][i->second] && heights[i->first][i->second] <= heights[row][col])
            {
                switch(pacificAtlantic(heights, i->first, i->second, visited, calcdFlows))
                {
                    case PACIFIC_AND_ATLANTIC:
                        thisSquaresFlow = PACIFIC_AND_ATLANTIC;
                        break;    
                    case PACIFIC: 
                        if(thisSquaresFlow == ATLANTIC || thisSquaresFlow == PACIFIC_AND_ATLANTIC)
                            thisSquaresFlow = PACIFIC_AND_ATLANTIC;
                        else
                            thisSquaresFlow = PACIFIC;
                        break;
                    case ATLANTIC:
                        if(thisSquaresFlow == PACIFIC || thisSquaresFlow == PACIFIC_AND_ATLANTIC)
                            thisSquaresFlow = PACIFIC_AND_ATLANTIC;
                        else
                            thisSquaresFlow = ATLANTIC;
                        break;
                    default:
                        break; 
                }

                // dont need to continue with other neighbors - we know we can get out to pacific and atlantic
                if(thisSquaresFlow == PACIFIC_AND_ATLANTIC)
                    break;
            }
        }
        visited[row][col] = false;

        // calcdFlows[row][col] = thisSquaresFlow;

        return thisSquaresFlow;
    }
};