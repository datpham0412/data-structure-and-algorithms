class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> firstIndex(26, -1);  // Initialize all indices to -1
        
        for (int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';  // Convert character to index
            if (firstIndex[index] == -1) {
                firstIndex[index] = i;  // Store the first occurrence
            } else {
                // Calculate the distance and check
                if (i - firstIndex[index] - 1 != distance[index]) {
                    return false;  // Return false if distances do not match
                }
            }
        }
        
        return true;  // Return true if all checked distances are correct
    }
};
