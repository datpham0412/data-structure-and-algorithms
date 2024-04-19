#include <vector>
// Time: O(n)
// space: O(n)
std::vector<int> rotateArray(const std::vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n; // Adjust k to be less than the size of the array
    std::vector<int> result;
    result.reserve(n); // Reserve space to avoid reallocations

    // Add the last k elements to the result
    for (int i = n - k; i < n; i++)
    {
        result.push_back(nums[i]);
    }

    // Add the rest of the elements
    for (int i = 0; i < n - k; i++)
    {
        result.push_back(nums[i]);
    }

    return result;
}
