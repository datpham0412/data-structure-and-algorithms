#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int counter = 0;
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j)
        {
            if (nums[j] - nums[i] == (2 * diff))
            {
                counter++;
            }
            i++;
        }
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j)
        {
            if (nums[j] - nums[i] == (2 * diff))
            {
                counter++;
            }
            j--;
        }

        return counter;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0, 1, 4, 6, 7, 10};
    int diff = 3;
    int result = solution.arithmeticTriplets(nums, diff);
    cout << result << endl;

    return 0;
}