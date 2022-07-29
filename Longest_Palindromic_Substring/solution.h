#include <iostream>

using namespace std;

class Solution {
public:

    vector<vector<bool>> substrIsPalindrome;
    string longestPalindrome(string s) {
        // initialize 2d array of bools to check past palindromes
        // also set substrs of size 1 to true
        for(int i = 0; i < s.size(); i++)
        {
            substrIsPalindrome.push_back({});
            for(int j = 0; j < s.size(); j++)
            {
                if(i == j)
                    substrIsPalindrome[i].push_back(true);
                else
                    substrIsPalindrome[i].push_back(false);
            }
        }

        int longestPalindromeLength = 1;
        int longestPalindromeX = 0;
        int longestPalindromeY = 0;

        // set substrs of size 2 to true if applicable
        for(int i = 0, j = 1; j < s.size(); i++, j++)
        {
            if(s[i] == s[j])
            {
                substrIsPalindrome[i][j] = true;
                longestPalindromeLength = 2;
                longestPalindromeX = i;
                longestPalindromeY = j;
            }
        }

        if(s.size() < 3)
            return s.substr(longestPalindromeX, longestPalindromeY - longestPalindromeX + 1);

        for(int i = 0; i < s.size() - 2; i++)
        {
            for(int j = i, k = i + 2; j >= 0 && k < s.size(); j--, k++)
            {
                if(substrIsPalindrome[j+1][k-1] && s[j] == s[k])
                {
                    substrIsPalindrome[j][k] = true;
                    if(k - j + 1 > longestPalindromeLength)
                    {
                        longestPalindromeX = j;
                        longestPalindromeY = k;
                        longestPalindromeLength = k - j + 1;
                    }
                }
                else
                    break;
            }
        }

        if(s.size() < 4)
            return s.substr(longestPalindromeX, longestPalindromeY - longestPalindromeX + 1);

        for(int i = 0; i < s.size() - 3; i++)
        {
            for(int j = i, k = i + 3; j >= 0 && k < s.size(); j--, k++)
            {
                if(substrIsPalindrome[j+1][k-1] && s[j] == s[k])
                {
                    substrIsPalindrome[j][k] = true;
                    if(k - j + 1 > longestPalindromeLength)
                    {
                        longestPalindromeX = j;
                        longestPalindromeY = k;
                        longestPalindromeLength = k - j + 1;
                    }
                }
                else
                    break;
            }
        }

        return s.substr(longestPalindromeX, longestPalindromeY - longestPalindromeX + 1);
    }

    string longestPalindromeAround(string s) {
        int longestPalindromeLength = 0;
        string::iterator longestPalindromeX = s.begin();
        string::iterator longestPalindromeY = s.begin();

        for(auto i = s.begin(); i != s.end(); i++)
        {
            //one in the middle
            for(auto j = i, k = i; j != std::prev(s.begin()) && k != s.end() ; j--, k++)
            {
                if(*j != *k)
                    break;
                if(std::distance(j, k) + 1 > longestPalindromeLength)
                {
                    longestPalindromeLength = std::distance(j, k) + 1;
                    longestPalindromeX = j;
                    longestPalindromeY = std::next(k);
                }
            }

            //two in the middle
            for(auto j = i, k = std::next(i); j != std::prev(s.begin()) && k != s.end() ; j--, k++)
            {
                if(*j != *k)
                    break;
                if(std::distance(j, k) + 1 > longestPalindromeLength)
                {
                    longestPalindromeLength = std::distance(j, k) + 1;
                    longestPalindromeX = j;
                    longestPalindromeY = std::next(k);
                }
            }
        }

        return string(longestPalindromeX, longestPalindromeY);
    }
};