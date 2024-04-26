class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[counter] != nums[i])
            {
                counter++;
                nums[counter] = nums[i];
            }
        }
        return counter + 1;
    }
};