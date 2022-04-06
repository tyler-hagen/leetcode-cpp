#include <unordered_set>

using namespace std;

class Solution {
public:
    const static int MIN_INT = -1000000;
    int maxSubArray(vector<int>& nums) {
        auto i = nums.begin();

        auto prefix = 0;
        auto max = MIN_INT;
        while(i != nums.end())
        {
            prefix += *i;
            if(prefix > max)
            {
                max = prefix;
            }
            if(prefix < 0)
            {
                prefix = 0;
            }
            i++;
        }

        return max;
    }

    int maxSubArrayRecursive(vector<int>& nums) {
        auto max = maxSubArrayRecursiveImpl(nums, 0, nums.size() - 1);

        return max;
    }

   int maxSubArrayRecursiveImpl(const vector<int>& nums, int begin, int end)
    {
        // base case
        if (begin == end)
        {
            return nums[begin];
        }

        int middle = (end - begin) / 2 + begin;

        auto leftReturn = maxSubArrayRecursiveImpl(nums, begin, middle);
        auto rightReturn = maxSubArrayRecursiveImpl(nums, middle + 1, end);    

        int maxCrossing = maxCrossingSum(nums, begin, middle, end);

         return max({leftReturn, rightReturn, maxCrossing});
    }

    int maxCrossingSum(const vector<int>& nums, int begin, int middle, int end)
    {
        int leftMax = MIN_INT;
        int leftSum = 0;
        for(auto i = middle; i >= begin; i--)
        {
            leftSum += nums[i];
            if(leftSum > leftMax)
                leftMax = leftSum;
        }

        int rightMax = MIN_INT;
        int rightSum = 0;
        for(auto i = middle + 1; i <= end; i++)
        {
            rightSum += nums[i];
            if(rightSum > rightMax)
            {
                rightMax = rightSum;
            }
        }

        return leftMax + rightMax;
    }
};