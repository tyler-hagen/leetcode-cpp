using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
        int min = 99999999;
        int profit = 0;
        for(auto i = prices.begin(); i != prices.end(); i++)
        {
            if(*i < min)
                min = *i;

            if(*i - min > profit)
            {
                profit = *i - min;
            }
        }

        return profit;
    }
};