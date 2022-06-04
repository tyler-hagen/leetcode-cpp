using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        
        int sum;
        int carry;
        do
        {
            sum = a ^ b;
            // left shift on a negative number is actually undefined behavior in the C++ standard,
            // so just tell the compiler its actually a unsigned int because were just using the bits
            // and dont care to actually interpret this number as any value here
            carry = (unsigned int)(a & b) << 1;
            a = sum;
            b = carry;
        }
        while(carry != 0);

        return sum;
    }
};