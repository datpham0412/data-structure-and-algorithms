#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++)
        {
            if (seen.find(nums[i]) != seen.end())
            {
                int diff = abs(i - seen[nums[i]]);
                if (diff <= k)
                {
                    return true;
                }
            }
            seen[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 1};
    int k = 2;
    bool result = solution.containsNearbyDuplicate(nums, k);
    cout << (result ? "true" : "false");
    return 0;
}