#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int product = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            product *= nums[i];
        }
        if (product > 0)
            return 1;
        else if (product < 0)
            return -1;
        else
            return 0;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0, 2, 3, 4, 5};
    int result = solution.arraySign(nums);
    cout << result;
    return 0;
}