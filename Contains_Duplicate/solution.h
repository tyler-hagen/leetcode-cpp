#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> map;

        for(auto i = nums.begin(); i != nums.end(); i++)
        {
            if(map.find(*i) != map.end())
            {
                return true;
            }

            map.insert(*i);
        }

        return false;
    }
};