#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < k)
            {
                counter++;
            }
        }
        return counter;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0, 1, 2, 10, 11};
    int k = 10;
    cout << solution.minOperations(nums, k) << endl;
    return 0;
}