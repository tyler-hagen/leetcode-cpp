#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    const int MOD_VAL = 1000000007;
    int numFactoredBinaryTrees(vector<int>& arr)
    {   
        
        unordered_set<int> valsEncountered;
        for(auto i = arr.begin(); i != arr.end(); i++)
        {
            valsEncountered.insert(*i);
        }
        
        // O(nlogn)
        std::sort(arr.begin(), arr.end());
        
        unordered_map<int,long long> numFactoredBinaryTrees;
        for(auto i = 0; i < arr.size(); i++)
        {   
            // advance to last value
            while(i+1 < arr.size() && arr[i] == arr[i+1])
                i++;
            
            // 1 for the val by itself
            long long thisIValSum = 1;
            
            for(auto j = 0; j < arr.size(); j++)
            {
                // if(arr[j] >= arr[i])
                //     break;
                // advance to last value
                while(j+1 < arr.size() && arr[j] == arr[j+1])
                    j++;
                
                if(arr[i] % arr[j] == 0 && valsEncountered.find(arr[i] / arr[j]) != valsEncountered.end())
                {
                    int denom = arr[i] / arr[j];
                    thisIValSum = (thisIValSum + ((numFactoredBinaryTrees[arr[j]] * numFactoredBinaryTrees[denom]) % MOD_VAL)) % MOD_VAL;
                }
            }
            numFactoredBinaryTrees[arr[i]] = thisIValSum;
        }

        int sum = 0;
        for(auto i = numFactoredBinaryTrees.begin(); i != numFactoredBinaryTrees.end(); i++)
        {
            sum= (sum + i->second) % MOD_VAL;
        }
        return sum;
    }
};