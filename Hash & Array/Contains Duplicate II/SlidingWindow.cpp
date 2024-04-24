#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> window;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k)
            {
                window.erase(nums[i - k - 1]);
            }
            if (!window.insert(nums[i]).second)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    bool result = solution.containsNearbyDuplicate(nums, k);
    cout << (result ? "true" : "false");
    return 0;
}