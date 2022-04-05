#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto i = nums.begin();

        auto prefix = 0;
        auto max = -1000000;
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
};