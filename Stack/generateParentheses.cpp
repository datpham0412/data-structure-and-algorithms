#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void solve(vector<string>& ans, string output, int open, int close) {
        if(open == 0 && close == 0) {
            ans.push_back(output);
            return;
        }

        if(open > 0) {
            output.push_back('(');
            solve(ans, output, open - 1, close);
            output.pop_back();
        }

        if(close > open) {
            output.push_back(')');
            solve(ans, output, open, close - 1);
            output.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output;
        solve(ans, output, n, n);
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 3; // Change this value to generate different results
    vector<string> result = solution.generateParenthesis(n);

    cout << "All combinations of well-formed parentheses for " << n << " pairs are:" << endl;
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
