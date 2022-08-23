#include <queue>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> s) 
    {
        return minRefuelStopsPq(target, startFuel, s);
    }

    int minRefuelStopsPq(int target, int startFuel, const vector<vector<int>>& s)
    {
        priority_queue<int> pq; 
        auto numRefuelStops = 0;
        auto pos = 0;
        auto stopsIter = 0;
        
        do
        {
            // we either can reach the target from here
            // or we can't, and we need to select the max fuel and go again

            if(target - pos <= startFuel)
                return numRefuelStops;
            pos += startFuel; 
            startFuel = 0; 
            while(stopsIter < s.size() && s[stopsIter][0] <= pos)
            {
                pq.push(s[stopsIter++][1]);
            }

            if(!pq.empty())
            {
                startFuel = pq.top(); pq.pop();
                numRefuelStops++;
            } 
        } 
        while (startFuel);
        
        if(target == pos)
            return numRefuelStops;
        return -1;
    }

    int minRefuelStopsDp(int target, int startFuel, vector<vector<int>> s) 
    {
        vector<int> furthestWithIRefuelingStops(s.size() + 1, 0);
        vector<bool> visited(s.size(), false);
        
        furthestWithIRefuelingStops[0] = startFuel;
        int i = 0;
        while(furthestWithIRefuelingStops[i] < target)
        {
            // take the maximum of all fuel stops between [0, furthestWith(i-1)fuelingstops]
            int maxRefuelingStopIdx = 0;
            int maxRefuelingAmount = 0;
            int j = 0;
            while(j < s.size() && s[j][0] <= furthestWithIRefuelingStops[i])
            {
                if(!visited[j] && s[j][1] >= maxRefuelingAmount)
                {
                    maxRefuelingStopIdx = j;
                    maxRefuelingAmount = s[j][1];
                }
                j++;
            }

            if(maxRefuelingAmount)
            {
                visited[maxRefuelingStopIdx] = true;
                furthestWithIRefuelingStops[i+1] = furthestWithIRefuelingStops[i] + s[maxRefuelingStopIdx][1];
            }
            else
                return -1;
            i++;
        }

        return i;
    }
};




