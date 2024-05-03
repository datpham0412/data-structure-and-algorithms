#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        vector<int> result(1, 1); // {1}
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i] += carry;
            if (digits[i] == 10)
            {
                digits[i] = 0;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }
        if (digits[0] == 0)
        {
            for (int i = 0; i < digits.size(); i++)
            {
                result.push_back(digits[i]);
            }
            return result;
        }
        else
        {
            return digits;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> digits = {9, 9};
    vector<int> result = solution.plusOne(digits);
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}