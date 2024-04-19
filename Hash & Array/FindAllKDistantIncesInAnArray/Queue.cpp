// Time: O(n)
// Space: O(n)

#include <iostream>
#include <vector>
#include <queue>

class Solution
{
public:
    std::vector<int> findKDistantIndices(std::vector<int> &nums, int key, int k)
    {
        int n = nums.size();
        std::queue<int> q; // Queue to hold the indices where nums[i] == key

        // Populate the queue with indices where the element is the key
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == key)
                q.push(i);
        }

        std::vector<int> ans; // Vector to hold the answer

        // Process each index and check if it is within k distance from any key index
        for (int i = 0; i < n; i++)
        {
            while (!q.empty() && i > q.front() + k)
            {
                // If current index i is beyond the k distance of the index at the front of the queue
                q.pop(); // Pop that index as it is no longer relevant
            }
            if (!q.empty() && abs(q.front() - i) <= k)
            {
                // If the front of the queue is within k distance, add i to the results
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = {3, 4, 9, 1, 3, 9, 5}; // Test case array
    int key = 9;                                   // Key to find in the array
    int k = 1;                                     // Distance from key index

    std::vector<int> result = sol.findKDistantIndices(nums, key, k);
    std::cout << "Output indices: ";
    for (int idx : result)
    {
        std::cout << idx << " ";
    }
    std::cout << std::endl;
    return 0;
}
