// Time: O(n^2) -> Since finding and erasing performing inside the loop
// Space: O(n)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_set<double> numSet;
        for (int i = 0; i < nums.size() / 2; i++)
        {
            numSet.insert((nums[i] + nums[nums.size() - i - 1]) / 2.0);
        }
        return numSet.size();
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 1, 4, 0, 3, 5};
    int result = s.distinctAverages(nums);
    cout << result;
    return 0;
}