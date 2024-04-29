#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class NumArray {
    private:
    vector <int> accumulate;
public:
    NumArray(vector<int>& nums) {
        accumulate.push_back(0);
        for (int i = 0; i < nums.size(); i++){
            accumulate.push_back(accumulate.back() + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return accumulate[right + 1] - accumulate[left];
    }
};

int main(){
    vector <int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* numArray = new NumArray(nums);
    cout << "Sum of range [0, 2]: " << numArray->sumRange(0, 2) << endl;  // Should output 1
    cout << "Sum of range [2, 5]: " << numArray->sumRange(2, 5) << endl;  // Should output -1
    cout << "Sum of range [0, 5]: " << numArray->sumRange(0, 5) << endl;  // Should output -3
    
    return 0;
}