// Time : - Best: O(n) - Worst : O(n^2)
// Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int counter = 0;
        unordered_map<int, vector<int>> seen;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < seen[nums[i]].size(); j++)
            {
                if (seen.count(nums[i]) && seen[nums[i]][j] * i % k == 0)
                {
                    counter++;
                }
            }
            seen[nums[i]].push_back(i);
        }
        return counter;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 1, 2, 2, 2, 1, 3};
    int k = 2;
    int result = solution.countPairs(nums, k);
    cout << result;
    return 0;
}