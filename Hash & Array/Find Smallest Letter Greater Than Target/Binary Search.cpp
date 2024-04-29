// Time: O(log n)
// SPace: O(1)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        if (target > letters.back() || target < letters[0])
        {
            return letters[0];
        }
        int low = 0;
        int high = letters.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (letters[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return letters[low];
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