#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (val != nums[i])
            {
                nums[counter] = nums[i];
                counter++;
            }
        }
        return counter;
    }
};

int main()
{
    // Example 1
    vector<int> nums = {3, 2, 2, 3};             // Input array
    int val = 3;                                 // Value to remove
    vector<int> expectedNums = {2, 2};           // The expected answer with correct length.
    int k = Solution().removeElement(nums, val); // Calls your implementation

    assert(k == expectedNums.size()); // Assert that the returned length k is as expected

    // Sort the first k elements of nums
    sort(nums.begin(), nums.begin() + k);

    // Assert to check each element up to the new length k
    for (int i = 0; i < k; i++)
    {
        assert(nums[i] == expectedNums[i]);
    }

    cout << "Test case passed!" << endl;

    // Example 2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};   // Input array
    int val2 = 2;                                   // Value to remove
    vector<int> expectedNums2 = {0, 1, 3, 0, 4};    // The expected answer with correct length.
    int k2 = Solution().removeElement(nums2, val2); // Calls your implementation

    assert(k2 == expectedNums2.size()); // Assert that the returned length k is as expected

    // Sort the first k elements of nums
    sort(nums2.begin(), nums2.begin() + k2);

    // Assert to check each element up to the new length k
    for (int i = 0; i < k2; i++)
    {
        assert(nums2[i] == expectedNums2[i]);
    }

    cout << "Test case 2 passed!" << endl;

    return 0;
}
