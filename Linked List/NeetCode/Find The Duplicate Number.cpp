#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // Initial positions for the tortoise and the hare
        int tortoise = nums[0];
        int hare = nums[nums[0]];

        // Phase 1: Finding the intersection point in the cycle
        while (tortoise != hare)
        {
            tortoise = nums[tortoise]; // Move tortoise by 1 step
            hare = nums[nums[hare]];   // Move hare by 2 steps
        }

        // Phase 2: Finding the entrance to the cycle (duplicate number)
        tortoise = 0; // Move tortoise back to the start
        while (tortoise != hare)
        {
            tortoise = nums[tortoise]; // Move tortoise by 1 step
            hare = nums[hare];         // Move hare by 1 step as well
        }

        // The point of intersection is the duplicate
        return tortoise;
    }
};

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2}; // Test case
    Solution solution;
    int duplicate = solution.findDuplicate(nums);
    cout << "The duplicate number is: " << duplicate << endl;

    return 0;
}
