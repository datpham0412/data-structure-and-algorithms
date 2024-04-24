// Time: O(n)
// Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        return numSet.size() - numSet.count(0);
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 3, 5, 0, 3};
    int result = solution.minimumOperations(nums);
    cout << result;
    return 0;
}