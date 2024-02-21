#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        unordered_set<char> charSet;
        int result = 0;
        while(right < s.size()){
            while (charSet.count(s[right])){
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};

int main(){
    Solution solution;
    string s = "pwwkew";
    int result = solution.lengthOfLongestSubstring(s);
    cout << result;
    return 0;
}