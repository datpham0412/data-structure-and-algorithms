// Time: O(n log n)
// Space: O(n)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countElements(vector<int> &nums)
    {
        set<int> numSet(nums.begin(), nums.end());
        vector<int> numVec(numSet.begin(), numSet.end());
        unordered_map<int, int> freq;
        if (numVec.size() <= 2)
        {
            return 0;
        }
        else
        {
            numVec.pop_back();
            numVec.erase(numVec.begin());
        }
        unordered_set<int> numUnSet(numVec.begin(), numVec.end());
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (numUnSet.count(nums[i]))
            {
                counter++;
            }
        }
        return counter;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {6, 3, 7, 3, 15, 6, 15};
    int result = solution.countElements(nums);
    cout << result;
    return 0;
}