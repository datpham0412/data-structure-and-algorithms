#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int unequalTriplets(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (int n : nums)
            ++m[n];
        int res = 0, left = 0, right = nums.size();
        for (auto [key, value] : m)
        {
            right -= value;
            res += left * value * right;
            left += value;
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> nums = {4, 4, 2, 4, 3};
    cout << solution->unequalTriplets(nums) << endl;
    return 0;
}
