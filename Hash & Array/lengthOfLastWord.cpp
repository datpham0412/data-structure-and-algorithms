#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution1
{
public:
    int lengthOfLastWord(string s)
    {
        int counter = 0;
        int ptr = s.size() - 1;

        // Skip trailing spaces
        while (ptr >= 0 && s[ptr] == ' ')
        {
            ptr--;
        }

        // Count the length of the last word
        while (ptr >= 0 && s[ptr] != ' ')
        {
            counter++;
            ptr--;
        }

        return counter;
    }
};
class Solution2
{
public:
    int lengthOfLastWord(string s)
    {
        istringstream iss(s);
        string word;
        while (iss >> word)
        {
        }
        return word.size();
    }
};

int main()
{
    Solution2 solution;
    // Test cases
    string test1 = "Hello World";
    string test2 = "   fly me   to   the moon  ";
    string test3 = "luffy is still joyboy";

    // Printing results
    cout << "Length of last word in \"" << test1 << "\": " << solution.lengthOfLastWord(test1) << endl; // Expected output: 5
    cout << "Length of last word in \"" << test2 << "\": " << solution.lengthOfLastWord(test2) << endl; // Expected output: 4
    cout << "Length of last word in \"" << test3 << "\": " << solution.lengthOfLastWord(test3) << endl; // Expected output: 6

    return 0;
}
