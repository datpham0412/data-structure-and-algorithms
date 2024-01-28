#include <iostream>
#include <vector>

class Solution{
    public:
    std::vector<int> productExceptSelf (std::vector<int> &nums){
        std::vector<int> result(nums.size(), 1);
        int prefix = 1;
        for (int i = 0; i < nums.size(); i ++){
            result[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for (int i = nums.size() - 1; i >= 0; i--){
            result[i] *= postfix;
            postfix *= nums[i];
        }
        return result;
    }
};


int main(){
    std::vector<int> nums = {1,2,3,4};
    Solution solution;
    std::vector<int> result = solution.productExceptSelf(nums);
    for (int i:result){
        std::cout<<i<<std::endl;
    }
    return 0;
}