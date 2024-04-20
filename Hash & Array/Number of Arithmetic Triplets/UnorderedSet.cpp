// Time : O(n)
// Space: O(n)

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int counter = 0;
        unordered_set <int> numSet (nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (numSet.count(nums[i] + diff) && numSet.count(nums[i] + (2*diff))){
                counter ++;
            }
        }
        return counter;
    }
};