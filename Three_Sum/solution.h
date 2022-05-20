#include <unordered_set>

using namespace std;

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ret;

        if(nums.size() < 3)
            return ret;

        // since we're shooting for O(n^2) time complexity, and we dont care to keep track of indexes, sort the array
        std::sort(nums.begin(), nums.end());

        for(auto i = nums.begin(); i != std::prev(nums.end(), 2); i++)
        {
            // don't process duplicates.
            if(i != nums.begin() && *i == *(std::prev(i)))
                continue;
            
            // 2 sum on remaining elements to the right. target is -i 
            auto left = std::next(i);
            auto right = std::prev(nums.end());
            auto target = -(*i);
            while(std::distance(nums.begin(), left) < std::distance(nums.begin(), right))
            {
                auto sum = *left + *right;
                if(sum == target)
                {
                    ret.push_back({*i, *left, *right});
                }
                if(sum <= target)
                {
                    left++;
                    while(left != nums.end() && *left == *(std::prev(left)))
                        left++;
                }
                if(sum >= target)
                {
                    right--;
                    while(right != nums.begin() && *right == *(std::next(right)))
                        right--;
                }
            }
        }

        return ret;
    }

    // vector<vector<int>> threeSum(vector<int>& nums) 
    // {    
    //     vector<vector<int>> retVal;
    //     unordered_set<int> dontConsider;

    //     for(auto i = nums.begin(); i != nums.end(); i++)
    //     {
    //         if(dontConsider.find(*i) != dontConsider.end())
    //             continue;
    //         int target = -(*i);
    //         auto matches = twoSum(std::next(i), nums.end(), dontConsider, target);
    //         for(auto j = matches.begin(); j != matches.end(); j++)
    //         {
    //             j->push_back(*i);
    //             retVal.push_back(*j);
    //         }
    //         dontConsider.insert(*i);
    //     }

    //     return retVal;
    // }

    // vector<vector<int>> twoSum(const vector<int>::iterator begin, const vector<int>::iterator end, const unordered_set<int>& dontConsider, int target)
    // {
    //     vector<vector<int>> ret;

    //     unordered_set<int> foundValues;
    //     unordered_set<int> alreadySuccesfullyAddedValues;

    //     for(auto i = begin; i != end; i++)
    //     {
    //         bool alreadySuccessfullyAdded = alreadySuccesfullyAddedValues.find(*i) != alreadySuccesfullyAddedValues.end();
    //         bool dontConsiderThis = dontConsider.find(*i) != dontConsider.end();
    //         if(alreadySuccessfullyAdded || dontConsiderThis)
    //             continue;
    //         int neededVal = target - *i;
    //         auto neededValItr = foundValues.find(neededVal);
    //         if(neededValItr != foundValues.end() && dontConsider.find(*neededValItr) == dontConsider.end())
    //         {
    //             ret.push_back({*i, *neededValItr});
    //             alreadySuccesfullyAddedValues.insert(*i);
    //             alreadySuccesfullyAddedValues.insert(*neededValItr);
    //         }

    //         foundValues.insert(*i);
    //     }

    //     return ret;
    // }
};