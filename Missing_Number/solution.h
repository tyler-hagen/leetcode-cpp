using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) { 
        int sum = 0;
        for(auto i = nums.size(); i > 0; i--)
        {
            sum += i;
        }
        
        for(auto i = nums.begin(); i != nums.end(); i++)
        {
            sum -= *i;
        }
        
        return sum;
    }

    int missingNumberXOR(vector<int>& nums) {
        int ret = 0;

        for(int i = 1; i <= nums.size(); i++)
        {
            ret = ret ^ i;
        }

        for(auto i = nums.begin(); i != nums.end(); i++)
        {
            ret = ret ^ *i;
        }

        return ret;      
    }
};