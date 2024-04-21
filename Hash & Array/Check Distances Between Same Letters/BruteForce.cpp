class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        for (int i = 0; i < s.length(); i++) {
            char current = s[i];  
            for (int j = i + 1; j < s.length(); j++) {
                if (current == s[j]) {  // Ensuring 'current' is the same as 's[j]'
                    int distBetween = j - i - 1;  
                    if (distBetween != distance[current - 'a']) {  // Direct comparison
                        return false;  // Return false immediately if the distance doesn't match
                    }
                }
            }
        }
        return true;  // Return true if no mismatches are found
    }
};