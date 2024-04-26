// Time: O(n)
// Space: O(m) (with a maximum of O(n) in the worst case scenario where all n numbers are unique and even)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                freq[nums[i]]++;
            }
        }
        int smallest = -1;
        int currentFreq = 0;
        for (auto [key, value] : freq)
        {
            if (value > currentFreq)
            {
                currentFreq = value;
                smallest = key;
            }
        }
        return (smallest != -1) ? smallest : -1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0, 1, 4, 4, 2, 2, 5};
    cout << solution.mostFrequentEven(nums) << endl;
    return 0;
}