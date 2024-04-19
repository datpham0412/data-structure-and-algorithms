#include <vector>
#include <unordered_set>
#include <iostream>

std::vector<int> findAllNumbersDisappeared(std::vector<int> nums)
{
    std::unordered_set<int> numSet(nums.begin(), nums.end());
    int length = nums.size();
    std::vector<int> result;
    for (int i = 1; i <= length; i++)
    { // Changed loop condition to use length
        if (!numSet.count(i))
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    // Test the function
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> disappearedNumbers = findAllNumbersDisappeared(nums);

    // Print the result
    std::cout << "Disappeared numbers: ";
    for (int num : disappearedNumbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

#include <vector>
#include <iostream>
#include <cmath> // For std::abs

std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
{
    // First pass: Mark each number that appears
    for (int i = 0; i < nums.size(); ++i)
    {
        int index = std::abs(nums[i]) - 1; // Adjusting for 0-based index
        if (nums[index] > 0)
        {
            nums[index] = -nums[index]; // Negate the number at the index
        }
    }

    // Second pass: Collect indices where values are not negated
    std::vector<int> result;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > 0)
        {
            result.push_back(i + 1); // +1 to adjust for 0-based index
        }
    }

    // Restore the original values by negating them back (if needed)
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] < 0)
        {
            nums[i] = -nums[i];
        }
    }

    return result;
}

int main()
{
    // Test the function
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> disappearedNumbers = findDisappearedNumbers(nums);

    // Print the result
    std::cout << "Disappeared numbers: ";
    for (int num : disappearedNumbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
