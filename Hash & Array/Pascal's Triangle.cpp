#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1, 1); // Create a row with i+1 elements, all initialized to 1
            for (int j = 1; j < i; j++)
            {
                // Set the value of the current element by adding the two elements directly above it in the triangle
                row[j] = result[i - 1][j] + result[i - 1][j - 1];
            }
            result.push_back(row);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int numRows = 5; // Change this value to generate more or fewer rows of Pascal's Triangle

    vector<vector<int>> pascalTriangle = solution.generate(numRows);

    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    for (const auto &row : pascalTriangle)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl; // Move to the next line after printing each row
    }

    return 0;
}
