// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    char repeatedCharacter(std::string s)
    {
        std::vector<int> freq(26, 0); // Frequency vector for letters 'a' to 'z'
        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a'; // Convert char to index (0-25)
            if (freq[index] < 1)
            {
                freq[index]++;
            }
            else
            {
                return s[i]; // Return the first character that repeats
            }
        }
        return ' '; // Return space if no repeated character is found
    }
};

int main()
{
    Solution sol;

    // Example test case
    std::string testString = "abcdeffedcba";
    char result = sol.repeatedCharacter(testString);

    std::cout << "The first repeated character in \"" << testString << "\" is '";
    if (result != ' ')
    {
        std::cout << result;
    }
    else
    {
        std::cout << "No repeated character";
    }
    std::cout << "'." << std::endl;

    return 0;
}
