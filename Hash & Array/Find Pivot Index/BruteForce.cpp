#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++){
            totalSum += nums[i];
        }
        for (int i = 0; i < nums.size(); i++){
            if (leftSum == totalSum - leftSum - nums[i]){
                return i;
            }
            leftSum += nums[i];
        }
      
        return -1;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,7,3,6,5,6};
    int result = solution.pivotIndex(nums);
    cout << result;
    return 0;
}