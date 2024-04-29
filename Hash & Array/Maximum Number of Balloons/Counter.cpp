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
        int b = 0;
        int a = 0;
        int l = 0;
        int o = 0;
        int n = 0;
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == 'a')
            {
                a++;
            }
            else if (text[i] == 'b')
            {
                b++;
            }
            else if (text[i] == 'l')
            {
                l++;
            }
            else if (text[i] == 'o')
            {
                o++;
            }
            else if (text[i] == 'n')
            {
                n++;
            }
        }
        l = l / 2;
        o = o / 2;
        result = min(result, a);
        result = min(result, b);
        result = min(result, l);
        result = min(result, o);
        result = min(result, n);
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