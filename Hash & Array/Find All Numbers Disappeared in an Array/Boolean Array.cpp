#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> result;
        int n = nums.size();
        vector<bool> mark(n + 1, false); // Vector to mark presence of numbers

        for (int num : nums)
        {
            if (num <= n)
            {
                mark[num] = true; // Mark the presence of the number
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (!mark[i])
            { // Check unmarked indices, which indicate missing numbers
                result.push_back(i);
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = solution.findDisappearedNumbers(nums);
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}
