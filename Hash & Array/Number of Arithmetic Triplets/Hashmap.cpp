// Time: O(n)
// Space: O(n)

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map <int, int> seen;
        int counter = 0;
        for (int i = 0; i < nums.size(); i++){
            seen[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++){
            if(seen.count(nums[i] + diff) && seen.count(nums[i] + (2*diff))){
                counter++;
            }
        }
        return counter;
    }
};