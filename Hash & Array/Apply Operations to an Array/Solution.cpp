#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        {
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i] == nums[i + 1])
                {
                    nums[i] = 2 * nums[i];
                    nums[i + 1] = 0;
                }
            }
            int snowBallSize = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                {
                    snowBallSize++;
                }
                else if (snowBallSize > 0)
                {
                    int temp = nums[i];
                    nums[i] = 0;
                    nums[i - snowBallSize] = temp;
                }
            }
            return nums;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 2, 1, 1, 0};
    vector<int> result = solution.applyOperations(nums);
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}