using namespace std;

class Solution 
{
    public:
        vector<int> twoSum(const vector<int>& nums, int target)
        {
            vector<int> ret;

            for(int i = 0; i < nums.size() - 1; i++)
            {
                for(int j = i; j < nums.size(); j++)
                {
                    if(nums[i] + nums[j] == target)
                    {
                        ret.push_back(i);
                        ret.push_back(j);
                    }
                }
            }

            return ret;
        }
    
        vector<int> mergeSort(vector<int> originalList)
        {
            // base case
            if(originalList.size() == 1)
                return originalList;

            int midpoint = originalList.size() / 2;
            vector<int> vect1;
            vector<int> vect2;

            vect1.assign(originalList.begin(), std::next(originalList.begin(), midpoint));
            vect2.assign(std::next(originalList.begin(), midpoint), originalList.end());

            return merge(mergeSort(vect1), mergeSort(vect2));
        }

        // merge two sorted lists
        vector<int> merge(const vector<int> list1, const vector <int> list2)
        {
            vector<int> retList;

            int i = 0;
            int j = 0;
            while(i < list1.size() && j < list2.size())
            {
                if(list1[i] < list2[j])
                {
                    retList.push_back(list1[i++]);
                }
                else
                {
                    retList.push_back(list2[j++]);
                }
            }

            while(i < list1.size())
            {
                retList.push_back(list1[i++]);
            }

            while(j < list2.size())
            {
                retList.push_back(list2[j++]);
            }

            return retList;
        }
};