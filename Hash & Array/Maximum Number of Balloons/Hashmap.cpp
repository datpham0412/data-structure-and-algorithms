// Time: O(n)
// Space: O(1)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int result = INT_MAX;
        unordered_map<char, int> seen;
        seen['b'] = 0;
        seen['a'] = 0;
        seen['l'] = 0;
        seen['o'] = 0;
        seen['n'] = 0;
        for (int i = 0; i < text.size(); i++)
        {
            if (seen.find(text[i]) != seen.end())
            {
                seen[text[i]]++;
            }
        }
        seen['l'] /= 2;
        seen['o'] /= 2;
        for (auto [key, value] : seen)
        {
            result = min(result, value);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string text = "loonbalxballpoon";
    int result = solution.maxNumberOfBalloons(text);
    cout << result << endl;
    return 0;
}