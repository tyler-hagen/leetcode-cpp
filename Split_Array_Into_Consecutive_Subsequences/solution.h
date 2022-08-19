#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
        unordered_map<int,int> count;
        unordered_map<int,int> ends;

        for(auto i = nums.begin(); i != nums.end(); i++)
        {
            count[*i]++;
        }

        for(auto num : nums)
        {
            if(!count[num])
                continue;
            if(ends[num-1])
            {
                ends[num-1]--;
                ends[num]++;
            }
            else if(count[num+1] && count[num+2])
            {
                count[num+1]--;
                count[num+2]--;
                ends[num+2]++;
            }
            else
                return false;
            count[num]--;
        }

        return true;
    }
};