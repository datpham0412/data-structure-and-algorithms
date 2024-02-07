// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    int binarySearch(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] < target){
                low = mid + 1;
            }else if(nums[mid > target]){
                high = mid - 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};

int main() {
    // Write C++ code here
    Solution solution;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    int result = solution.binarySearch(nums, target);
    cout << result;
    return 0;
}