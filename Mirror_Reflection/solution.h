
using namespace std;

class Solution 
{
public:
    int mirrorReflection(int p, int q) {
        int ref = 1; 
        int ext = 1;
        while( q * ref != ext * p)
        {
            ref++;
            if(q * ref > ext * p)
                ext++;
        }

        if(ref % 2 == 1 && ext % 2 == 1)
            return 1; 
        if(ref % 2 == 0 && ext % 2 == 1)
            return 2;
    
        return 0;            
        
    }      
};