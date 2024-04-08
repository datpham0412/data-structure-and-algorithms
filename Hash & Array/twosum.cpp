#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> *nums, int *target)
    {
        std::unordered_map<int, int> seen;
        int n = nums->size();
        for (int i = 0; i < n; i++)
        {
            int diff = *target - (*nums)[i];
            if (seen.count(diff))
            {
                return {seen[diff], i};
            }
            else
            {
                seen[(*nums)[i]] = i;
            }
        }
        return {};
    }
};

int main()
{
    std::vector<int> nums = {2, 11, 7, 15};
    int target = 9;

    Solution solution;
    std::vector<int> result = solution.twoSum(&nums, &target);

    if (!result.empty())
    {
        std::cout << "Indices: [" << result[0] << ", " << result[1] << "]" << std::endl;
    }
    else
    {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}
