#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int count = nums.size() / 2;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
            if (freq[nums[i]] > count)
            {
                return nums[i];
            }
        }
        return 1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << solution.majorityElement(nums) << endl;

    return 0;
}