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
        unordered_map<double, int> avgFreq;
        while (nums.size() > 1)
        {
            auto maxIter = max_element(nums.begin(), nums.end());
            auto minIter = min_element(nums.begin(), nums.end());

            double maxValue = *maxIter;
            double minValue = *minIter;

            double avg = (maxValue + minValue) / 2.0;
            avgFreq[avg]++;

            nums.erase(maxIter);
            if (minIter > maxIter)
            {
                minIter = find(nums.begin(), nums.end(), minValue);
            }
            nums.erase(minIter);
        }
        return avgFreq.size();
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