using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int maxArea = -1;
        for(auto i = height.begin(); i != std::prev(height.end()); i++)
        for(auto j = std::next(height.begin()); j != height.end(); j++)
        {
            int minHeight = *i > *j ? *j : *i;
            int width = std::distance(i, j);
            int area = minHeight * width;

            maxArea = maxArea > area ? maxArea : area;
        }

        return maxArea;
    }
};