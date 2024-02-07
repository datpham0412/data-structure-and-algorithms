#include <iostream>
#include <vector>

using namespace std;
class Solution{
    public:
    int largestRectangle(vector<int> &heights){
        int maxArea = 0;
        vector<pair<int,int>> stack; //pair: index, height

        for(int i = 0; i < heights.size(); ++i){
            int start = i;
            while(!stack.empty() && stack.back().second > heights[i]){
                int stackIndex = stack.back().first;
                int stackHeight = stack.back().second;
                stack.pop_back();
                maxArea = max(maxArea, stackHeight * (i - stackIndex));
                start = stackIndex;
            }
            stack.push_back({start, heights[i]});
        }
        for (auto [index, height]: stack){
            maxArea = max(maxArea, height * static_cast<int>(heights.size() - index));
        }
        return maxArea;
    } 
};

int main(){
    Solution solution;
    vector<int> heights = {2,1,5,6,2,3};
    int result = solution.largestRectangle(heights);
    cout << result;
    return 0;
}