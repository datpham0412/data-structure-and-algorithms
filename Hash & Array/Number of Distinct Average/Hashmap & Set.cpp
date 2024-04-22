// Time: O(n^2) -> Since finding and erasing performing inside the loop
// Space: O(n)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 1, 4, 0, 3, 5};
    int result = s.distinctAverages(nums);
    cout << result;
    return 0;
}