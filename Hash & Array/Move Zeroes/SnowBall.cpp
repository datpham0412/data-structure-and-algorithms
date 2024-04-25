class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int snowBallSize = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                snowBallSize ++;
            }
            else if (snowBallSize >= 1){
                int temp = nums[i];
                nums[i] = 0;
                nums[i - snowBallSize] = temp;
            }
        }
    }
};