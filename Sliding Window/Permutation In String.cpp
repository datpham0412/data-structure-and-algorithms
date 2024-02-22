/*
    Given 2 strings, return true if s2 contains permutation of s1
    Ex. s1 = "ab", s2 = "eidbaooo" -> true, s2 contains "ba"

    Sliding window, expand + count down char, contract + count up char

    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
private:
    bool isPermutation(vector<int> &count){
        for(int i = 0; i < 26; i++){
            if(count[i] != 0){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        
        if(len1 > len2){
            return false;
        }
        vector<int> count(26,0);
        for(int i = 0; i < len1; i++){
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        if(isPermutation(count)){
            return true;
        }
        for(int i = len1; i < len2; i++){
            count[s2[i] - 'a']--;
            count[s2[i - len1] - 'a']++;
            if(isPermutation(count)){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution solution;
    string s1 = "abc";
    string s2 = "baxyzbca";
    bool result = solution.checkInclusion(s1, s2);
    cout << (result ? "true" : "false");
    return 0;
}