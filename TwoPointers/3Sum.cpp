#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> resultSet;
        for(int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            int target = 0;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < target){
                    j ++;
                }
                else if (sum > target){
                    k --;
                }
                else{
                    resultSet.insert({nums[i], nums[j], nums[k]});
                    j++; --k;
                }

            }
        }
        vector<vector<int>> result(resultSet.begin(), resultSet.end());
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = solution.threeSum(nums);

    cout << "Output: ";
    for ( auto triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ",";
        }
        cout << "]";
        if (&triplet != &result.back()) cout << ",";
    }
    cout << endl;

    return 0;
}