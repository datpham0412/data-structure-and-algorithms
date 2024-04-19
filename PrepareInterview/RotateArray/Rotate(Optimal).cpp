#include <vector>
#include <iostream>
#include <algorithm> // For std::reverse

void rotate(std::vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n; // Normalize k to be within the range of 0 to n-1

    // Reverse the entire array
    std::reverse(nums.begin(), nums.end());

    // Reverse the first k elements
    std::reverse(nums.begin(), nums.begin() + k);

    // Reverse the remaining n-k elements
    std::reverse(nums.begin() + k, nums.end());
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3; // Number of steps to rotate the array to the right

    rotate(nums, k);

    std::cout << "Rotated Array: ";
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
