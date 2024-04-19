// Time: O(n)
// SPace: O(1)
// each boolean value: 1 bit
// vector of 26 boolean -> 26 bits in total

#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    char repeatedCharacter(std::string s)
    {
        std::vector<bool> seen(26, false); // Array to keep track of seen characters

        for (char c : s)
        {
            int index = c - 'a'; // Convert character to index (0-25)
            if (seen[index])
            {             // Check if the character has been seen before
                return c; // Return the first repeated character
            }
            seen[index] = true; // Mark this character as seen
        }
        return ' '; // Return a space if there is no repeated character
    }
};

int main()
{
    Solution sol;
    std::string testString = "abccba"; // Example test case
    char result = sol.repeatedCharacter(testString);

    std::cout << "The first repeated character in \"" << testString << "\" is '";
    if (result != ' ')
    {
        std::cout << result;
    }
    else
    {
        std::cout << "no repeated character";
    }
    std::cout << "'." << std::endl;

    return 0;
}
