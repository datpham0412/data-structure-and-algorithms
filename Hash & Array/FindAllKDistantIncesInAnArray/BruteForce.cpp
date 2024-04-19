#include <iostream>
#include <vector>
#include <set>
#include <cmath> // For std::abs
// Time: O(n^2)
// Space: O(n)
class Solution
{
public:
    std::vector<int> findKDistantIndices(std::vector<int> &nums, int key, int k)
    {
        std::vector<int> j;   // To store indices where nums[i] == key
        std::set<int> numSet; // To store results without duplicates and sorted

        // Find all indices where the element equals key
        for (int i = 0; i < nums.size(); i++)
        {
            if (key == nums[i])
            {
                j.push_back(i); // Add index to vector
            }
        }

        // Check each element in nums to see if it is within k distance of any key index
        for (int i = 0; i < nums.size(); i++)
        {
            for (int e = 0; e < j.size(); e++)
            {
                if (std::abs(i - j[e]) <= k)
                {
                    numSet.insert(i); // Add to set to handle duplicates and order
                }
            }
        }

        // Convert set to vector
        std::vector<int> result(numSet.begin(), numSet.end());
        return result;
    }
};

void printVector(const std::vector<int> &vec)
{
    for (int num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Solution sol;

    // Test case 1
    std::vector<int> nums1 = {3, 4, 9, 1, 3, 9, 5};
    int key1 = 9, k1 = 1;
    std::vector<int> result1 = sol.findKDistantIndices(nums1, key1, k1);
    std::cout << "Test Case 1: ";
    printVector(result1);

    // Test case 2
    std::vector<int> nums2 = {2, 2, 2, 2, 2};
    int key2 = 2, k2 = 2;
    std::vector<int> result2 = sol.findKDistantIndices(nums2, key2, k2);
    std::cout << "Test Case 2: ";
    printVector(result2);

    return 0;
}
