#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> combinationSums;

    int combinationSum4(vector<int>& nums, int target) {
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        if(combinationSums.find(target) != combinationSums.end())
            return combinationSums[target];
        
        int sum = 0;
        for(auto i = nums.begin(); i != nums.end(); i++)
        {
            sum += combinationSum4(nums, target - *i);
        }

        combinationSums[target] = sum;

        return combinationSums[target];      
    }
};


//1 2 3 target = 4 expected = 7