#include <iostream>
#include <vector>

using namespace std;

class Solution1
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            result.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            result.push_back(nums[i]);
        }
        return result;
    }
};

class Solution2
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> result;
        int length = nums.size();
        for (int i = 0; i < 2 * length; i++)
        {
            result.push_back(nums[i % length]);
        }
        return result;
    }
};

int main()
{
    // Initialize the vector with some values
    vector<int> nums = {1, 3, 2, 1};

    // Create an instance of the Solution class
    Solution2 sol;

    // Get the concatenated array
    vector<int> ans = sol.getConcatenation(nums);

    // Output the resulting array
    cout << "Output: [";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
