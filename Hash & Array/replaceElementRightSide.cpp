// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

class Solution1
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int n = arr.size();
        int maxSoFar = arr[n - 1];
        arr[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            int temp = maxSoFar;
            if (maxSoFar < arr[i])
            {
                maxSoFar = arr[i];
            }
            arr[i] = temp;
        }
        return arr;
    }
};

class Solution2
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int n = arr.size();
        int maxSoFar = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            int temp = arr[i];
            arr[i] = maxSoFar;
            maxSoFar = max(maxSoFar, temp);
        }
        return arr;
    }
};

int main()
{
    Solution2 solution;
    vector<int> arr = {17, 18, 5, 4, 6, 1};
    vector<int> result = solution.replaceElements(arr);
    for (int n : arr)
    {
        cout << n << " ";
    }

    return 0;
}