#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int result = 0;
        for (int i  = 0; i < colors.size(); i++){
            if (colors[i] != colors[0]){
                result = max(result, i);
            }
            if (colors[i] != colors[colors.size() - 1]){
                result = max(result, static_cast<int>(colors.size()) - i - 1);
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector <int> colors = {1,1,1,6,1,1,1};
    int result = solution.maxDistance(colors);
    cout << result;
    return 0;
}