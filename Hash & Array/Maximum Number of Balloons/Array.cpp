// Time: O(n)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int chars[26] = {0};
        int result;
        for (int i = 0; i < text.size(); i++)
        {
            chars[text[i] - 'a']++;
        }
        result = chars[1];                   // for b
        result = min(result, chars[0]);      // for a
        result = min(result, chars[11] / 2); // for l
        result = min(result, chars[14] / 2); // for o
        result = min(result, chars[13]);     // for n
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