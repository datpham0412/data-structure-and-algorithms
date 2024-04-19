// Recursion
// Using recursion to solve the problem involves breaking down the string into smaller substrings and solving for those. However, this approach can quickly become complex and inefficient for large strings due to the overhead of recursive calls and the difficulty in managing multiple nested structures without auxiliary storage like a stack.
#include <iostream>
#include <string>
// Time Complexity: O(n^3)
// Substring Operations: Each recursive call potentially involves creating a substring when a matching pair of parentheses is found and removed. The substr() operation itself can take O(n) time in the worst case, where n is the length of the string.
// Recursion Depth and Iterations: The function looks for pairs to remove by iterating through the string. In the worst case, a valid pair might always be found at the end of the string, leading to nearly n/2 removals (for n being even and all characters being part of valid pairs).
// Recursive Calls: For each found pair, a recursive call is made on a string that's shorter by two characters. Considering the cost of each substring operation and the fact that you might end up making a recursive call for every pair (approximately n/2 calls for n characters), the cumulative time spent on these operations can multiply quickly.
// Given these factors, each level of recursion could involve a linear scan followed by creating a new substring that is also a linear-time operation, and doing this n/2 times recursively can lead to a cubic time complexity in the worst case.

// Space Complexity: O(n^2)
// Recursive Call Stack: Each recursive call adds a level to the call stack. In the worst-case scenario, where each call processes just a pair and recurses, you might end up with n/2 levels in the call stack if the pairs are nested or lined up such that each call processes just one pair. Since each call could involve a new substring, which itself can take space up to O(n), the total space due to recursive calls can accumulate.
// String Storage: Each recursive call potentially creates a new substring. If substrings are not optimized and each is a copy, the total space taken up by all substrings across all calls could also contribute significantly to the space complexity. However, in many modern C++ implementations, substrings share memory with the original string until modifications are made, which could mitigate this somewhat.
bool isValidRecursively(std::string s)
{
    int n = s.length();
    if (n == 0)
        return true; // An empty string is a valid configuration
    if (n % 2 != 0)
        return false; // Any odd-length string cannot be fully matched

    // Search for a pair and recurse
    for (int i = 0; i < n - 1; i++)
    {
        if ((s[i] == '(' && s[i + 1] == ')') ||
            (s[i] == '{' && s[i + 1] == '}') ||
            (s[i] == '[' && s[i + 1] == ']'))
        {
            // Remove the found pair and recurse on the reduced string
            std::string reduced = s.substr(0, i) + s.substr(i + 2);
            return isValidRecursively(reduced);
        }
    }
    return false; // No valid pairs to remove
}

int main()
{
    std::string input = "{[]}";
    std::cout << "The string " << input << " is "
              << (isValidRecursively(input) ? "valid" : "invalid") << ".\n";
    return 0;
}
