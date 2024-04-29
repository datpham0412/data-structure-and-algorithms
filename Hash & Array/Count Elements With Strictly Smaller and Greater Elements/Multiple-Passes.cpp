// Time: O(3n) = O(n)
// Space: O(1)
// Min-Max using multiple passes
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countElements(vector<int> &nums)
    {
        int counter = 0;
        int minElement = *min_element(nums.begin(), nums.end());
        int maxElement = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > minElement && nums[i] < maxElement)
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