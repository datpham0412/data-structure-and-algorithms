#include <iostream>
#include <vector>
// Time: O(n)
// SPace: O(n)

void rotateWithAuxArray(std::vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n; // Normalize k to be within the range of 0 to n-1

    std::vector<int> temp(n); // Create a temporary array to hold the rotated elements

    // Place each element in the original array into its new position in the temporary array
    for (int i = 0; i < n; ++i)
    {
        temp[(i + k) % n] = nums[i];
    }

    // Copy the temporary array back to the original array
    nums = temp;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3; // Number of steps to rotate the array to the right

    rotateWithAuxArray(nums, k);

    std::cout << "Rotated Array: ";
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
