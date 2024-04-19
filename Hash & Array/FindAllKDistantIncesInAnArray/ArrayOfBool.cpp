#include <vector>
#include <iostream>
#include <algorithm> // For std::max and std::min
using namespace std;
class Solution
{
public:
    vector<int> findKDistantIndices(const vector<int> &nums, int key, int k)
    {
        int n = nums.size();               // size = 7
        vector<bool> isKDistant(n, false); // To mark if index is within k-distance of key
        vector<int> result;
        // isKDistant {false, false, false, false, false, false, false, false}
        // Scan through the array to find all positions of the key
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == key)
            { // nums [2] , nums[5] satisfied
                int start = max(0, i - k);
                // with nums[2], start = max(0, 2-1) = 1;
                //  with nums[5], start = max(0, 5-1) = 4
                int end = min(n - 1, i + k);
                // with nums[2], end = min (7-1, 2+1) = min (6,3) = 3
                // with nums[5], end = min(7-1, 5+1) = 6
                for (int j = start; j <= end; ++j)
                {
                    // Case i = 2: start = 1; end = 3 j iterate from 1 -> 3
                    // Case i = 5; start = 4; end = 6 j iterate from 4 -> 6
                    isKDistant[j] = true;
                    // case i = 2{false, true, true, true, false, false, false, false}
                    // case i = 5 {false, false, false, false, true, true, true}
                    // Consequenly the isKDistant is: {false, true,true,true,true,true,true}
                }
            }
        }

        // Collect indices that are marked as k-distant
        for (int i = 0; i < n; ++i)
        {
            if (isKDistant[i])
            {
                result.push_back(i); // result: [1,2,3,4,5,6]
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
    int key = 9, k = 1;
    auto result = sol.findKDistantIndices(nums, key, k);
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}