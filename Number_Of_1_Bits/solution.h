using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int hammingWeight = 0;
        while(n != 0)
        {
            if(n % 2 != 0)
                hammingWeight++;
            n = n / 2;
        }
        
        return hammingWeight;
    }
};