#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int counter = 0;
        unordered_map<int, int> freq;  // Store the frequency of each number
        for (int i = 0; i < nums.size(); i++) {
            if (freq.count(nums[i] + k)) {
                counter += freq[nums[i] + k];
            }
            if (freq.count(nums[i] - k)) {
                counter += freq[nums[i] - k];
            }
            freq[nums[i]]++;  // Increment frequency of the current number
        }
        return counter;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2, 1};  // Sample input
    int k = 1;
    int result = solution.countKDifference(nums, k);
    cout << "Number of pairs with absolute difference " << k << ": " << result << endl;

    return 0;
}
