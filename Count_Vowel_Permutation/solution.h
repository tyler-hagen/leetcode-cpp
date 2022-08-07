#include <unordered_map>
using namespace std;

class Solution {
public:
    const int MODULO_VAL = 1000000007;

    int countVowelPermutation(int n) {
        vector<unordered_map<char, int>> lastCharCounts;
        lastCharCounts.reserve(n);

        unordered_map<char, int> lengthOneCounts; 
        lengthOneCounts['a'] = 1;
        lengthOneCounts['e'] = 1;
        lengthOneCounts['i'] = 1;
        lengthOneCounts['o'] = 1;
        lengthOneCounts['u'] = 1;

        lastCharCounts.push_back(lengthOneCounts);

        for(int i = 1; i < n; i++)
        {
            lastCharCounts.emplace_back();
            lastCharCounts[i]['e'] = (lastCharCounts[i-1]['a'] + lastCharCounts[i-1]['i']) % MODULO_VAL;
            lastCharCounts[i]['a'] = ((lastCharCounts[i-1]['e'] + lastCharCounts[i-1]['i']) % MODULO_VAL + lastCharCounts[i-1]['u']) % MODULO_VAL;
            lastCharCounts[i]['i'] = (lastCharCounts[i-1]['e'] + lastCharCounts[i-1]['o']) % MODULO_VAL;
            lastCharCounts[i]['o'] = lastCharCounts[i-1]['i']; 
            lastCharCounts[i]['u'] = (lastCharCounts[i-1]['i'] + lastCharCounts[i-1]['o']) % MODULO_VAL; 
        }

        int sum = 0;
        for(auto i = lastCharCounts[n-1].begin(); i != lastCharCounts[n-1].end(); i++)
        {
            sum = (sum + i->second) % MODULO_VAL;
        }
        return sum;
    }
};