#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    int firstUniqChar(std::string s)
    {
        std::unordered_map<char, int> freq; // Map to store frequency of each character

        // Fill the map with frequency counts of each character
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i]]++;
        }

        // Find the first character that appears only once
        for (int i = 0; i < s.size(); i++)
        {
            if (freq[s[i]] == 1)
            {
                return i; // Return the index of the first unique character
            }
        }

        return -1; // Return -1 if no unique character is found
    }
};

int main()
{
    Solution sol;

    // Test cases
    std::string test1 = "leetcode";
    std::string test2 = "loveleetcode";
    std::string test3 = "aabb";

    std::cout << "Index of first non-repeating character in \"" << test1 << "\": " << sol.firstUniqChar(test1) << std::endl;
    std::cout << "Index of first non-repeating character in \"" << test2 << "\": " << sol.firstUniqChar(test2) << std::endl;
    std::cout << "Index of first non-repeating character in \"" << test3 << "\": " << sol.firstUniqChar(test3) << std::endl;

    return 0;
}
