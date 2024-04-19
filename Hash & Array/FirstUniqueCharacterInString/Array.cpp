#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    int firstUniqChar(std::string s)
    {
        std::vector<int> freq(26, 0); // Array to hold frequency of each character

        // Increment the count for each character in the string
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }

        // Check for the first character that appears only once
        for (int i = 0; i < s.size(); i++)
        {
            if (freq[s[i] - 'a'] == 1)
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
