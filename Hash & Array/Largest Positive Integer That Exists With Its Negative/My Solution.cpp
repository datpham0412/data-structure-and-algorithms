#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int maxPos = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0 && numSet.count(-nums[i]))
            {
                int currentPos = nums[i];
                maxPos = max(currentPos, maxPos);
            }
        }
        return maxPos != 0 ? maxPos : -1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-10, 8, 6, 7, -2, -3};
    int result = solution.findMaxK(nums);
    cout << result;
    return 0;
}