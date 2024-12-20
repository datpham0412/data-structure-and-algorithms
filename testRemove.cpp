#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> result (26,0);
        unordered_map <char,int> seen;
        for (int i = 0; i < s.size(); i++){
            if(seen.count(s[i])){
                result[s[i] - 'a'] = i - seen[s[i]] - 1;
            }
            seen[s[i]] = i;
        }
        for (int i = 0; i < 26; i++){
            if(result[i] != distance[i]){
                return false;
            }
            return true;
        }
        return true;
    }
};
int main(){
        Solution solution;
        string s = "zz";
        vector <int> distance = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
        bool result = solution.checkDistances(s, distance);
        cout << (result ? "true" : "fasle");
        return 0;
}