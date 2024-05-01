#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int countNegative = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                return 0;
            }
            else if (nums[i] < 0)
            {
                countNegative++;
            }
        }
        return (countNegative % 2 == 0 ? 1 : -1);
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    int result = solution.arraySign(nums);
    cout << result;
    return 0;
}