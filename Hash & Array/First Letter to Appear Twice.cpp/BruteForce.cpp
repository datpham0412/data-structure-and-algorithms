#include <iostream>
#include <unordered_set>
#include <string>

class Solution
{
public:
    char repeatedCharacter(std::string s)
    {
        std::unordered_set<char> charSet; // Set to track characters

        // Iterate over each character in the string
        for (int i = 0; i < s.size(); i++)
        {
            // Check if character is already in the set
            if (charSet.count(s[i]))
            {
                // If character is found, return it as it is the first repeated character
                return s[i];
            }
            // If not found, add the character to the set
            charSet.insert(s[i]);
        }
        // If no repeated character is found, return a space (indicating no repetition)
        return ' ';
    }
};

int main()
{
    Solution sol;

    // Test case
    std::string testString = "abccba";
    char result = sol.repeatedCharacter(testString);
    std::cout << "The first repeated character in \"" << testString << "\" is '" << result << "'." << std::endl;

    return 0;
}
