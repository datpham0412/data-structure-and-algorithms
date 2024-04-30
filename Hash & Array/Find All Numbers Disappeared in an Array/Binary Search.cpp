// Time: O(n log n)
// Space: O(1)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    bool binarySearch(vector<int> nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            else if (target > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }

public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> result;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size(); i++)
        {
            if (!binarySearch(nums, i))
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