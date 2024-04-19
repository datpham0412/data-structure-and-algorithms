#include <iostream>
#include <string>

class Solution
{
public:
    int firstUniqChar(std::string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            bool isUnique = true;
            for (int j = 0; j < s.size(); j++)
            {
                if (i != j && s[i] == s[j])
                {
                    isUnique = false;
                    break; // No need to check further if we found a duplicate
                }
            }
            if (isUnique)
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
