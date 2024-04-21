#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    bool findSubarrays(vector<int> &nums)
    {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int currSum = nums[i] + nums[i + 1];
            if (numMap.count(currSum))
            {
                return true;
            }
            numMap[currSum] = i;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    bool result = solution.findSubarrays(nums);
    cout << (result ? "true" : "false");
    return 0;
}