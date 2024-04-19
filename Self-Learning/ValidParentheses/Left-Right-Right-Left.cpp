// This method involves two passes:

// First Pass (Left-to-Right): Check if the opening brackets are balanced with closing brackets without considering types.
// Second Pass (Right-to-Left): Check if the closing brackets balance the opening ones, this time considering types.
// Note: This approach can become quite complicated and prone to errors because it struggles to correctly handle nested structures.

// Time: O(n)
// SPace: O(n)

#include <iostream>
#include <string>
#include <vector>

bool isValid(const std::string &s)
{
    // Counters for each type of bracket
    int round = 0, curly = 0, square = 0;

    // First pass: check for equal numbers of each type of bracket
    for (char c : s)
    {
        if (c == '(')
            round++;
        else if (c == ')')
            round--;
        else if (c == '{')
            curly++;
        else if (c == '}')
            curly--;
        else if (c == '[')
            square++;
        else if (c == ']')
            square--;

        // If counters go negative, there are unmatched closing brackets
        if (round < 0 || curly < 0 || square < 0)
            return false;
    }

    // If all counters are not zero, there are unmatched opening brackets
    if (round != 0 || curly != 0 || square != 0)
        return false;

    // Second pass (right-to-left): Check for correct sequence
    std::vector<char> stack;
    for (int i = s.length() - 1; i >= 0; --i)
    {
        char c = s[i];
        if (c == ')' || c == '}' || c == ']')
            stack.push_back(c);
        else
        {
            if (stack.empty())
                return false; // Unmatched opening bracket

            char last = stack.back();
            stack.pop_back();
            if ((c == '(' && last != ')') ||
                (c == '{' && last != '}') ||
                (c == '[' && last != ']'))
                return false; // Mismatched types
        }
    }

    return true; // If all checks pass
}

int main()
{
    std::string input = "{[]}";
    std::cout << "The string " << input << " is "
              << (isValid(input) ? "valid" : "invalid") << ".\n";
    return 0;
}
