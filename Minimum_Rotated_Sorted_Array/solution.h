#include <unordered_set>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int furthestLeftValue = nums[0];
        int midpoint = nums.size() / 2;
        int midpointValue = nums[midpoint];
        int furthestRightValue = nums[nums.size() - 1];


        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2 && nums[0])
            return nums[0] < nums[1] ? nums[0] : nums[1];
            
        if(furthestLeftValue < midpointValue && midpointValue < furthestRightValue)
            return furthestLeftValue;

        // transition happened on the left side
        if(midpointValue < furthestLeftValue)
        {
            vector<int> leftVector(nums.begin(), std::next(nums.begin(), midpoint + 1));
            return findMin(leftVector);
        }
        else
        {
            vector<int> rightVector(std::next(nums.begin(), midpoint), nums.end());
            return findMin(rightVector);
        } 
    }
};