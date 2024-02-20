// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;
    
class Solution{
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0;
        int col = cols - 1;
        
        while (row < rows && col >= 0){
            int curr = matrix[row][col];
            if(curr == target){return true;}
            else if(curr > target){col--;}
            else{row++;}
        }
        return false;
       
}
};

int main() {
    // Write C++ code here
    Solution solution;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    bool result = solution.searchMatrix(matrix, target);
    cout << (result ? "true":"false");
    return 0;
}