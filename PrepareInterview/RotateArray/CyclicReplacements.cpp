#include <iostream>
#include <vector>
// Time: O(n)
// Space: O(1)
void rotate(std::vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n; // Normalize k to ensure it is within the bounds of the array length

    int count = 0; // Tracks the number of elements placed in their final position
    for (int start = 0; count < n; start++)
    {
        int current = start;
        int prev = nums[start];
        int next = (current + k) % n;
        // Start the cycle
        while (start != next)
        {
            int temp = nums[next];
            nums[next] = prev;
            prev = temp;
            current = next;
            next = (current + k) % n;
            count++;
        }
        // To handle the last replacement which completes the cycle
        nums[next] = prev;
        count++;
    }
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);

    std::cout << "Rotated Array: ";
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
