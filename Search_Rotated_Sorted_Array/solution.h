#include <unordered_set>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
    
    int search(vector<int>& nums, int target, int left, int right)
    {
        int mid = (right - left) / 2 + left;
     
        // base case.
        if(left == mid)
        {
            if(nums[left] == target)
                return left;
            else if(nums[right] == target)
                return right;
            else
                return -1;
        }
        
        // the left array is sorted.
        if(nums[left] <= nums[mid])
        {
            // in range of the sorted array? 
            if(nums[left] <= target && nums[mid] >= target)
                return search(nums, target, left, mid);
            // its in the other array
            else
                return search(nums, target, mid, right);
        }
        // the right array is sorted.
        else
        {
            if(nums[right] >= target && nums[mid] <= target)
                return search(nums, target, mid, right);
            else
                return search(nums, target, left, mid);
        }
        
        
    }
};