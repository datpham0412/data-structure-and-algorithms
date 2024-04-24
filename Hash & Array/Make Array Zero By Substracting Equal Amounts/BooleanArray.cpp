// Since the constraint is small, we can use a boolean array to store the presence of each number.
// We can then iterate through the array and count the number of true values.
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int operations = 0;
        int present[101] = {false};
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                present[nums[i]] = true;
            }
        }
        for (int i = 1; i < 101; i++)
        {
            if (present[i])
            {
                operations++;
            }
        }
        return operations;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 3, 5, 0, 3};
    int result = solution.minimumOperations(nums);
    cout << result;
    return 0;
}