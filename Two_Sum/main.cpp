#include <vector>
#include <iostream>
#include "solution.h"

using namespace std;

int main()
{
    vector<int> nums = {1, 0, 3, -1, 15, 7}; 

    Solution sol;

    vector<int> ret = sol.twoSum(nums, 1);

    for (int i: ret)
        cout << i << ' ';

    cout << endl;

    cout << "testing sort" << endl;

    vector<int> sortedNums = sol.mergeSort(nums);

    for (int i: sortedNums)
        cout << i << ' ';
}