#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
        }
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[counter]);
                counter++;
            }
        }
        return nums;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 2, 1, 1, 0};
    vector<int> result = solution.applyOperations(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    return 0;
}