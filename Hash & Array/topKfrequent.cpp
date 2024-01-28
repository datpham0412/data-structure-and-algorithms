#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
    public:
    std::vector<int> topKfrequent(std::vector<int>&nums, int &k){
        std::unordered_map<int,int> count_num;
        for (char c : nums){
            count_num[c]++;
        }
        std::vector<std::vector<int>> bucket(nums.size()+1);
        for(auto [key, value]: count_num){
            bucket[value].push_back(key);
        }
        std::vector<int> result;
        for(int i = bucket.size()-1; i>=0; i--){
            for(int n : bucket[i]){
                result.push_back(n);
                if (result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    std::vector<int> result = solution.topKfrequent(nums, k);
    for (int i: result){
        std::cout<<i<<std::endl;
    }
    return 0;


}