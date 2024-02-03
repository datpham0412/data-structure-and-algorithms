#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    vector<int> twoSum(vector<int> &nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        vector<int> result;
        while (left < right){
            int sum = nums[left] + nums[right];
            if (sum < target){
                left ++;
            }
            else if (sum > target){
                right --;
            }
            else{
                result.push_back(left + 1);
                result.push_back(right + 1);
                break;
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    for (int i: result){
        cout << i << ",";
    }
    return 0;
}