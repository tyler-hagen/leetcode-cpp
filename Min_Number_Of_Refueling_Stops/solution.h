using namespace std;

class Solution {
public:
     int minRefuelStops(int target, int startFuel, vector<vector<int>> s) 
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




