// Here's how the Boyer-Moore Voting Algorithm works:

// Initialization: Start with two variables: one for storing the candidate of the majority element (candidate) and one for counting (count).
// First Pass:
// Traverse through the array.
// If count is 0, set the current element as the candidate.
// If the current element is the same as candidate, increase count. Otherwise, decrease count.
// Second Pass (optional in this specific problem due to the assumption that a majority element always exists):
// Verify that the candidate is the majority element by counting its occurrences to ensure it appears more than ⌊n / 2⌋ times.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int candidate = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                candidate = nums[i];
            }
            count += (candidate == nums[i]) ? 1 : -1;
        }
        return candidate;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << solution.majorityElement(nums) << endl;

    return 0;
}