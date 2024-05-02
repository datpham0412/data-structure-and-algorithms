#include <iostream>

// Mock implementation of isBadVersion API
// Assume "bad" is a global variable initialized with the first bad version number
int bad; // This should be set to the first bad version in your tests

bool isBadVersion(int version)
{
    return version >= bad;
}

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1;
        int right = n;
        while (left < right)
        {
            int mid = left + (right - left) / 2; // Prevents potential overflow
            if (isBadVersion(mid))
            {
                right = mid; // Narrow down the left search boundary
            }
            else
            {
                left = mid + 1; // Narrow down the right search boundary
            }
        }
        return left; // When left == right, we have found the first bad version
    }
};

int main()
{
    Solution solution;
    // Example test cases
    bad = 4; // Setting the first bad version
    std::cout << "The first bad version for n = 5 is " << solution.firstBadVersion(5) << std::endl;

    bad = 1; // Setting the first bad version
    std::cout << "The first bad version for n = 1 is " << solution.firstBadVersion(1) << std::endl;

    return 0;
}
