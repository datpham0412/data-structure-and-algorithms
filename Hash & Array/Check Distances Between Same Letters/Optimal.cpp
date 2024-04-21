class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map <char,int> seen;
        for (int i = 0; i < s.size(); i++){
            if(seen.count(s[i])){
                if (distance[s[i] - 'a'] != i - seen[s[i]] - 1){
                    return false;
                }
            }
            seen[s[i]] = i;
        }
        return true;
    }
};