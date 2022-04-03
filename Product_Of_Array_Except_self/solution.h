using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> retVal(nums.size(), 1);

        for(auto i = std::next(retVal.begin()), j = nums.begin(); i != retVal.end(); i++, j++)
        {
            *i = *j * *std::prev(i);
        }

        int multiplier = 1;
        for(auto i = std::next(retVal.rbegin()), j = std::next(nums.rbegin()); i != retVal.rend(); i++, j++)
        {
            multiplier *= *std::prev(j);
            *i *= multiplier;
        }
        
        return retVal;      
    }
};