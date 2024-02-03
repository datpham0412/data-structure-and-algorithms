#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    bool isPalindrome(string s){
        int left = 0;
        int right = s.size() - 1;
        while (left <= right){
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right --;
                continue;
            }
            if(tolower(s[left]) == tolower(s[right])){
                left++;
                right --;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    string s = "A man, a plan, a canal: Panama";
    bool res = solution.isPalindrome(s);
    cout << res ? "true": "false";
    return 0;
}