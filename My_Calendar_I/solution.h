#include <map>

using namespace std;

class MyCalendar {
public:
    MyCalendar() {
        intervals = map<int,int>(std::less<int>());
    }
    
    bool book(int start, int end) {
        intervals[start] += 1;
        intervals[end] -= 1;

        int sum = 0;
        auto i = intervals.begin();
        while(i != intervals.find(end))
        {
            sum += i->second; 
            if(sum > 1)
                break;
            i++;
        }

        if(sum > 1)
        {
            intervals[start]--;
            intervals[end]++;
            return false;
        }

        return true;
    }

private:
    map<int,int> intervals;
};