#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
  public:
  int trappinRainWater(vector<int> height){
      int l = 0;
      int r = height.size() - 1;
      int leftMax = height[l];
      int rightMax = height[r];
      int result = 0;
      while (l < r){
          if(leftMax < rightMax){
              l++;
              leftMax = max(leftMax, height[l]);
              result += leftMax - height[l];
          }else{
              r--;
              rightMax = max(rightMax, height[r]);
              result += rightMax - height[r];
          }
      }
      return result;
  }
};

int main() {
    // Write C++ code here
    Solution solution;
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = solution.trappinRainWater(heights);
    cout<<result;
    return 0;
}