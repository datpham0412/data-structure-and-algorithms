// Time: O(m + n)
// Space: O(n)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nums1Index;
        for (int i = 0; i < nums1.size(); i++){
            nums1Index[nums1[i]] = i;
        }
        stack <int> monoStack;
        vector <int> result (nums1.size(), -1);
        for (int i = 0; i < nums2.size(); i++){
            while (!monoStack.empty() && monoStack.top() < nums2[i]){
                int last = monoStack.top();
                monoStack.pop();
                result[nums1Index[last]] = nums2[i];
            }
            if (nums1Index.find(nums2[i]) != nums1Index.end()){
                monoStack.push(nums2[i]);
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector <int> nums1 = {4,1,2};
    vector <int> nums2 = {1,3,4,2};
    vector<int> result = solution.nextGreaterElement(nums1, nums2);
    for (int num: result){
        cout << num << " ";
    }
    return 0;
}