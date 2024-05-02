#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int sumBase(int n, int k)
    {
        // Test case: n = 72; k = 5 --> expected output = 2 + 4 + 2 = 8
        int remainder = 0;
        while (n != 0)
        {
            remainder += (n % k); // 0 + 2 = 2 + 4 = 6 + 2
            n = n / k;            // 72 / 5 = 14 - remainder 2 - 14 / 5 = 2 remain 4 - 2 / 5 = 0 remain 2
        }
        return remainder;
    }
};

int main()
{
    Solution solution;
    int n = 72;
    int k = 5;
    int result = solution.sumBase(n, k);
    cout << result << endl;
    return 0;
}