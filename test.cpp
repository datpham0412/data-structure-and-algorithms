// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <climits>

using namespace std;
    
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int rigt = 0;

        int minStart = 0;
        int minLength = INT_MAX;

        int counter = 0;
        
    }
};
int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution solution;
    string result = solution.minWindow(s, t);

    cout << "Minimum window substring: " << result << endl;

    return 0;
}
