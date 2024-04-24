// Time: O(n^2)
// Space: O(1)
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int product = i * j;
                if (nums[i] == nums[j] && product % k == 0)
                {
                    counter++;
                }
            }
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