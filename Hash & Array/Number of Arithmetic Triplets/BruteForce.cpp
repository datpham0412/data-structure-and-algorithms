// Time: O(n^3)
// Space: O(1)

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                for (int k = j + 1; k < nums.size(); k++){
                    if(nums[k] - nums[j] == diff && nums[j] - nums[i] == diff){
                        counter ++;
                    }
                }
            }
        }   
        return counter;
    }
};