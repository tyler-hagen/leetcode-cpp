using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int maxArea = -1;

        auto i = height.begin();
        auto j = std::prev(height.end());
        while(i != j)
        {
            auto minHeight = std::min(*i, *j);
            auto distance = std::distance(i, j);
            auto area = minHeight * distance;
            maxArea = area > maxArea ? area : maxArea;

            if(*i > *j)
                j--;
            else
                i++;
        }

        return maxArea;
    }
};