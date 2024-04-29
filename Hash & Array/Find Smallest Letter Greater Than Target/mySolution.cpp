#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        vector<int> myChar(26, 0);
        for (int i = 0; i < letters.size(); i++)
        {
            myChar[letters[i] - 'a']++;
        }
        int targetInd = target - 'a';
        for (int i = targetInd + 1; i < 26; i++)
        {
            if (myChar[i] >= 1)
            {
                return 'a' + i;
            }
        }
        for (int i = 0; i <= targetInd; i++)
        {
            if (myChar[i] >= 1)
            {
                return 'a' + i;
            }
        }
        return letters[0];
    }
};

int main()
{
    Solution solution;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    cout << solution.nextGreatestLetter(letters, target) << endl;
    return 0;
}