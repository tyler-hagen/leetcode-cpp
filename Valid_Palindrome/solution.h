#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        auto i = s.begin();
        auto j = s.rbegin();

        while(std::distance(i, std::next(j).base()) > 0 )
        {
            if(!isCharacter(*i))
            {
                i++;
                continue;
            }
            if(!isCharacter(*j))
            {
                j++;
                continue;
            }

            if(std::tolower(*i) != std::tolower(*j))
                return false;

            i++;
            j++;        
        }

        return true;
    }

    bool isCharacter(char c)
    {
        return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
    }
};