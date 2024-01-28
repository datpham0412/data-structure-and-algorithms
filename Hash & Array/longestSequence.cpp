#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int n : nums) {
            // Check if it's the start of a sequence
            if (!numSet.count(n-1)) {
                int length = 0;
                while (numSet.count(n+length)) {
                    length ++;
                }
                longest = std::max(length, longest);
            }
        }
        return longest;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    std::cout << "The length of the longest consecutive elements sequence is: "
              << solution.longestConsecutive(nums) << std::endl;
    return 0;
}
