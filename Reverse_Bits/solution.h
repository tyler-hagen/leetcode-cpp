using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed_bits = 0;
        
        for(int i = 0; i < 32; i++)
        {
            int lastbit = n % 2;
            n /= 2;
            
            reversed_bits *= 2;
            reversed_bits += lastbit;
        }
        
        return reversed_bits;
    }
};