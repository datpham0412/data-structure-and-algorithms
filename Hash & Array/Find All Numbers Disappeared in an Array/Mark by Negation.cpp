// Time: O(n)
// Space: O(1)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> result;
        // [3,2,1,6,7,1,2,0]
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0)
            {
                nums[index] = -nums[index];
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                result.push_back(nums[i + 1]);
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