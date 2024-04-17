#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution1
{
public:
    bool isSubsequence(string s, string t)
    // Time: O(n)
    // Space: O(1)
    {
        if (s.size() > t.size())
        {
            return false;
        }
        queue<char> q;
        for (char c : s)
        {
            q.push(c);
        }
        for (char c : t)
        {
            if (!q.empty() && c == q.front())
            {
                q.pop();
            }
        }
        return q.empty();
    }
};
class Solution2
{
public:
    bool isSubsequence(string s, string t)
    // Time: O(n)
    // Space: O(1)
    {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size())
        {
            if (s[i] == t[j])
            {
                i++;
            }
            j++;
        }
        return (i >= s.size() ? true : false);
    }
};

int main()
{
    Solution2 solution;

    // Test case 1: Should return true
    string s1 = "abc";
    string t1 = "ahbgdc";
    bool result1 = solution.isSubsequence(s1, t1);
    cout << "Test case 1: " << (result1 ? "true" : "false") << endl; // Expected output: true

    // Test case 2: Should return false
    string s2 = "axc";
    string t2 = "ahbgdc";
    bool result2 = solution.isSubsequence(s2, t2);
    cout << "Test case 2: " << (result2 ? "true" : "false") << endl; // Expected output: false

    return 0;
}
