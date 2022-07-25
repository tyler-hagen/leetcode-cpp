#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;

        for(auto i = s.begin(); i != s.end(); i++)
        {
            if(*i == '(' || *i == '{' || *i == '[')
            {
                st.push(*i);
                continue;
            }

            if(st.empty())
                return false;

            if(*i == ')' &&  st.top() != '(')
                return false;
            if(*i == '}' &&  st.top() != '{')
                return false;
            if(*i == ']' &&  st.top() != '[')
                return false;
            st.pop();
        }
        
        return st.empty();
    }
};