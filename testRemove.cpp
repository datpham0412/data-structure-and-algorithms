Example 1 :

    Input : nums = [ 3, 4, 9, 1, 3, 9, 5 ],
            key = 9, k = 1 Output : [ 1, 2, 3, 4, 5, 6 ] Explanation : Here, nums[2] == key and nums[5] == key.- For index 0, | 0 - 2 | > k and | 0 - 5 | > k, so there is no j where | 0 - j | <= k and nums[j] == key.Thus, 0 is not a k - distant index.- For index 1, | 1 - 2 | <= k and nums[2] == key, so 1 is a k - distant index.- For index 2, | 2 - 2 | <= k and nums[2] == key, so 2 is a k - distant index.- For index 3, | 3 - 2 | <= k and nums[2] == key, so 3 is a k - distant index.- For index 4, | 4 - 5 | <= k and nums[5] == key, so 4 is a k - distant index.- For index 5, | 5 - 5 | <= k and nums[5] == key, so 5 is a k - distant index.- For index 6, | 6 - 5 | <= k and nums[5] == key, so 6 is a k - distant index.Thus, we return [ 1, 2, 3, 4, 5, 6 ] which is sorted in increasing order.Example 2 :

    Input : nums = [ 2, 2, 2, 2, 2 ],
            key = 2, k = 2 Output : [ 0, 1, 2, 3, 4 ] Explanation : For all indices i in nums, there exists some index j such that | i - j | <= k and nums[j] == key, so every index is a k - distant index.Hence, we return [ 0, 1, 2, 3, 4 ].

#include <vector>
#include <iostream>
#include <algorithm> // For std::max and std::min

                                                                                                                                                                                                                   [3, 4, 9, 1, 3, 9, 5] class Solution
{
public:
    std::vector<int> findKDistantIndices(const std::vector<int> &nums, int key, int k)
    {
        int n = nums.size();                    // size = 7
        std::vector<bool> isKDistant(n, false); // To mark if index is within k-distance of key
        std::vector<int> result;
        // isKDistant {false, false, false, false, false, false, false, false}
        // Scan through the array to find all positions of the key
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == key)
            { // nums [2] , nums[5] satisfied
                int start = std::max(0, i - k);
                // with nums[2], start = max(0, 2-1) = 1;
                //  with nums[5], start = max(0, 5-1) = 4
                int end = std::min(n - 1, i + k);
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
                result.push_back(i);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
    int key = 9, k = 1;
    auto result = sol.findKDistantIndices(nums, key, k);
    for (int x : result)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
