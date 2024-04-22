// Time: O(n^2)
// Space: O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] < target)
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
    vector<int> nums = {-6, 2, 5, -2, -7, -1, 3};
    int target = -2;
    int result = solution.countPairs(nums, target);
    cout << result;
}