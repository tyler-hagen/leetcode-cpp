
using namespace std;

class Solution {
public:

    vector<int> cacheLIS;

    int lengthOfLIS(vector<int>& nums) 
    {
        return lengthOfLISDynamic(nums);  
    }

    int lengthOfLISDynamic(vector<int>& nums)
    {
        cacheLIS.resize(nums.size());
        cacheLIS[nums.size() - 1] = 1;

        for(int i = nums.size()-2; i >= 0; i--)
        {
            int max = 1;
            for(int j = i + 1; j < nums.size(); j++)
            {
                max = nums[i] < nums[j] && max < cacheLIS[j] + 1 ? cacheLIS[j] + 1 : max; 
            }

            cacheLIS[i] = max;
        }

        return *std::max_element(cacheLIS.begin(), cacheLIS.end());
    }

    int lengthOfLISRec(vector<int>& nums)
    {
        cacheLIS.resize(nums.size());
        std::fill(cacheLIS.begin(), cacheLIS.end(), 0);

        int max = 0;
        for(auto i = 0; i < nums.size(); i++)
        {
            int length = lengthOfLISRecImpl(nums, i);
            max = length > max ? length : max;
        }

        return max;    
    }

    int lengthOfLISRecImpl(const vector<int>& nums, int idx)
    {
        if(cacheLIS[idx] != 0)
            return cacheLIS[idx];
        if(idx == nums.size() - 1)
            return 1;
        
        int max = 0; 
        for(int i = idx + 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[idx])
            {
                int length = 1 + lengthOfLISRecImpl(nums, i);
                max = length > max ? length : max;
            }
        }

        if(max == 0)
        {
            cacheLIS[idx] = 1;
            return 1;
        }
        else
        {
            cacheLIS[idx] = max;
            return max;
        }
    }
};