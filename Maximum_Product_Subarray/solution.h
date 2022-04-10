#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = nums[0];
        int curContiguousMax = nums[0];
        int curContiguousMin = nums[0];
        for(auto i = std::next(nums.begin()); i != nums.end(); i++)
        {
            int tempContiguousMax = curContiguousMax;
            curContiguousMax = std::max({*i, *i * curContiguousMin, *i * curContiguousMax});
            curContiguousMin = std::min({*i, *i * curContiguousMin, *i * tempContiguousMax});
            max = std::max(max, curContiguousMax);
        }
        return max;
    }
};