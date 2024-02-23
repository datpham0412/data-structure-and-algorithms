// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int left = 0;
        int right = 0;
        int result = 0;
        int max_freq = 0;
        while (right < s.size()){
            count[s[right] - 'A']++;
            max_freq = max(max_freq, count[s[right] - 'A']);
            while (k < (right - left + 1) - max_freq){
                count[s[left] - 'A']--;
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};
int main() {
    Solution solution;
    // Test case where no replacements are needed (all characters are the same)
    cout << "Test Case 1: " << solution.characterReplacement("ABBAABBAABBA", 3) << endl;

    return 0;
}