#include <unordered_set>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int furthestLeftValue = nums[0];
        int midpoint = nums.size() / 2;
        int midpointValue = nums[midpoint];
        int furthestRightValue = nums[nums.size() - 1];

        // transition happened on the left side
        if(midpointValue < furthestLeftValue)
        {
            vector<int> leftVector(nums.begin(), std::next(nums.begin(), midpoint + 1));
            return findMin(leftVector);
        }
        else if(midpointValue > furthestRightValue)
        {
            vector<int> rightVector(std::next(nums.begin(), midpoint + 1), nums.end());
            return findMin(rightVector);
        } 
        else
        {
            return furthestLeftValue;
        }
    }
};