#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector <string> ans, string output, int open, int close){
        if(open == close == 0){
            ans.push_back(output);
            return;
        }
        if(open > 0){
            output.push_back('(');
            solve(ans, output, open - 1, close);
            output.pop_back();
        }
        if(close > open){
            output.push_back(')');
            solve(ans, output, open, close - 1);
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
    vector <string> ans = {};
    string output = "";
    solve(ans, output, n, n);
    return ans;
    }
};

int main(){
    Solution solution;
    int n  = 3;
    vector<string> result = solution.generateParenthesis(n);
    for (auto n: result){
        cout << n;
    }
    return 0;
}