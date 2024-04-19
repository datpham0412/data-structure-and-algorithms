#include <iostream>
#include <vector>
using namespace std;

// Time: O(n)
// Space: O(n)

class Solution
{
public:
    bool validParentheses(string &str)
    {
        vector<char> stack;
        for (char s : str)
        {
            if (s == '(' || s == '[' || s == '{')
            {
                stack.push_back(s);
            }
            else
            {
                if (stack.empty())
                {
                    return false; // No matching open bracket found
                }
                char top = stack.back();
                if ((s == ')' && top != '(') ||
                    (s == ']' && top != '[') ||
                    (s == '}' && top != '{'))
                {
                    return false; // Mismatched open and close brackets
                }
                stack.pop_back(); // Remove the matching open bracket
            }
        }
        return stack.empty(); // If the stack is empty, all brackets matched
    }
};

int main()
{
    string s = "([]{})";
    Solution solution;
    bool result = solution.validParentheses(s);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
