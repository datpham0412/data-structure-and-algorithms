#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string result;
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size() - 1];
        for (size_t i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] != last[i])
            {
                return result;
            }
            result += first[i];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> strs = {"flight", "flow", "flower"};

    // Calculate and print the longest common prefix
    string lcp = solution.longestCommonPrefix(strs);
    cout << "The longest common prefix is: '" << lcp << "'" << endl; // Expected output: 'fl'

    return 0;
}
