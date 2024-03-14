#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_set <char> count;
	int left  = 0;
	int right = 0;
	int longest = 0;
	while (right < s.size()){
		while (count.count(s[left])){
			count.erase(s[left]);
			left++;
		}
		count.insert(s[right]);
		longest = max(longest, right - left + 1);
		right ++;
	}
	return longest;
    }
};

int main(){
	Solution solution;
	string s = "pwwkew";
	int result = solution.lengthOfLongestSubstring(s);
	cout << result << endl;
	return 0;Z

}