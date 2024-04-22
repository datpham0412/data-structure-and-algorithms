// Time: O(n^2)
// Space: O(1)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        int counter = 0;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum < target)
            {
                counter += (right - left); // All sum between left and right are valid
                left++;
            }
            else
            {
                right--;
            }
        }
        return counter;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-6, 2, 5, -2, -7, -1, 3};
    int target = -2;
    int result = solution.countPairs(nums, target);
    cout << result;
}