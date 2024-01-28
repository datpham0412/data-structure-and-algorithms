#include <iostream>
#include <vector>
#include <unordered_set>

class Solution{
    public:
    bool containsDuplicate(std::vector<int>&nums){
        std::unordered_set<int> num_set;
        for (int i : nums){
            if(num_set.count(i)){
                return true;
            }else{
                num_set.insert(i);
            }
        }return false;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {1,1,2,3};
    bool result = solution.containsDuplicate(nums);
    std::cout<< result <<std::endl;

}