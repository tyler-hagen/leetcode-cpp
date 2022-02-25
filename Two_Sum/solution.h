#include <unordered_map>
using namespace std;

class Solution 
{
    public:
        vector<int> twoSum(const vector<int>& nums, int target)
        {
            vector<int> ret;

            unordered_map<int, int> theMap;

            for(auto i = nums.begin(); i < nums.end(); i++)
            {
                int neededVal = target - *i;
                auto neededValItr = theMap.find(neededVal);
                if(neededValItr != theMap.end())
                {
                    ret.push_back(neededValItr->second);
                    ret.push_back(distance(nums.begin(), i));
                    break;
                }

                pair<int, int> insertPair(*i, distance(nums.begin(), i));
                theMap.insert(insertPair);
            }


            return ret;
        }
};