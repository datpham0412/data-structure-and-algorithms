// TIme : O(n^2)
// Space: O(n)

// The reason for time complexity of O(n^2) since find in array take O(n) time complexity 
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++){
            if ((find(nums.begin(), nums.end(), nums[i] + diff) != nums.end()) &&
                (find(nums.begin(), nums.end(), nums[i] + (2*diff))!= nums.end())){
                    counter ++;
                }
         }
        return counter;
    }
};