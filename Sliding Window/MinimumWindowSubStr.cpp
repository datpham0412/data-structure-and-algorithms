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
        int right = 0;
        
        int minStart = 0;
        int minLength = INT_MAX;
        int counter = t.size();
        
        unordered_map<char,int> count;
        for (int i = 0; i < t.size(); i++){
            count[t[i]] ++;
        }
        
        while(right < s.size()){
            if(count[s[right]] > 0){
                counter--;
            }       
            count[s[right]]--;
            right++;
            while(counter == 0){
                if(right - left < minLength){
                    minStart = left;
                    minLength = right - left;
                }
                count[s[left]] ++;
                if(count[s[left]] > 0){
                    counter++;
                }
                left++;
            }
        }
        if(minLength != INT_MAX){
            return s.substr(minStart, minLength);
        }
        return "";
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
