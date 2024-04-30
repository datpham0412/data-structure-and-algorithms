// Time: O(n)
// Space: O(n)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> result;
        unordered_set<int> numSet(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size(); i++)
        {
            if (numSet.find(i) == numSet.end())
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = solution.findDisappearedNumbers(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    return 0;
}