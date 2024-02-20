// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high){
            int mid = low + (high - low)/2;
            if (nums[mid] < nums[high]){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return nums[low];
    }
};

int main() {
    // Write C++ code here
    Solution solution;
    vector<int> nums = {3,4,5,1,2};
    int min = solution.findMin(nums);
    cout << min << endl;

    return 0;
}