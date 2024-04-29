// Time: O(n)
// Space: O(n)
// Min-Max using single pass
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countElements(vector<int> &nums)
    {
        int minElement = INT_MAX;
        int maxElement = INT_MIN;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
            minElement = min(minElement, nums[i]);
            maxElement = max(maxElement, nums[i]);
        }
        if (minElement == maxElement)
        {
            return 0;
        }
        return nums.size() - freq[minElement] - freq[maxElement];
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