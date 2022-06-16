using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1, 0);

        auto leftIdx = 0;
        auto rightIdx = 1;
        auto nextReset = rightIdx * 2; 
        while(rightIdx <= n)
        {
            ret[rightIdx++] = ret[leftIdx++] + 1;
            if(rightIdx == nextReset)
            {
                leftIdx = 0;
                nextReset *= 2;
            }
        }

        return ret;
    }
};