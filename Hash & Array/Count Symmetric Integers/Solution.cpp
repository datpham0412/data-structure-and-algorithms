#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int counter = 0;
        for (int i = low; i <= high; i++)
        {
            if (isSymmetric(i))
                counter++;
        }
        return counter;
    }
    bool isSymmetric(int element)
    {
        string num = to_string(element); // "1203"
        int length = num.size();         // 4
        if (length % 2 == 1)
        {
            return false;
        }
        int leftSum = 0;
        int rightSum = 0;
        for (int i = 0; i < length / 2; i++)
        {
            leftSum += (num[i] - '0');
            rightSum += (num[length - 1 - i] - '0');
        }
        return leftSum == rightSum;
    }
};

int main()
{
    Solution solution;
    int low = 1200;
    int high = 1230;
    int result = solution.countSymmetricIntegers(low, high);
    cout << result << endl;
    return 0;
}