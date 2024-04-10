#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> num_set;
        for (int i : nums)
        {
            if (num_set.count(i))
            {
                return true;
            }
            else
            {
                num_set.insert(i);
            }
        }
        return false;
    }
};

int main()
{
    Solution *solution = new Solution();                         // Dynamically allocate Solution object on heap
    std::vector<int> *nums = new std::vector<int>({1, 1, 2, 3}); // Dynamically allocate vector on heap

    bool result = solution->containsDuplicate(*nums); // Dereference nums to pass by reference
    std::cout << result << std::endl;

    delete solution; // Clean up Solution object
    delete nums;     // Clean up vector

    return 0;
}
