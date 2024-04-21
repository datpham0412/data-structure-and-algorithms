// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> result (26,-1); // Use -1 to indicate the letter does not appear
        unordered_map <char,int> seen;
        for (int i = 0; i < s.size(); i++){
            if(seen.count(s[i])){
                result[s[i] - 'a'] = i - seen[s[i]] - 1;
            }
            seen[s[i]] = i;
        }
        for (int i = 0; i < 26; i++){
            if(result[i] != -1 && result[i] != distance[i]){
                return false;
            }
        }
        return true;
    }
};
int main(){
        Solution solution;
        string s = "zz";
        vector <int> distance = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
        bool result = solution.checkDistances(s, distance);
        cout << (result ? "true" : "false");
        return 0;
}