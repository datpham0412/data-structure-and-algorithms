// Time: O(n)
// Space: O(n)
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        int height = 0;
        return dfs(root, height);
    }

private:
    bool dfs(TreeNode *root, int &height)
    {
        if (root == nullptr)
        {
            return true;
        }

        int leftHeight = 0, rightHeight = 0;

        if (!dfs(root->left, leftHeight) || !dfs(root->right, rightHeight))
        {
            return false;
        }
        if (abs(leftHeight - rightHeight) > 1)
        {
            return false;
        }

        height = 1 + max(leftHeight, rightHeight);
        return true;
    }
};

int main()
{
    // Test case 1: Balanced binary tree
    TreeNode *root1 = new TreeNode(1,
                                   new TreeNode(2,
                                                new TreeNode(4),
                                                new TreeNode(5)),
                                   new TreeNode(3));
    Solution solution;
    cout << "Test case 1 is balanced: " << solution.isBalanced(root1) << endl; // Should print 1 (true)

    // Test case 2: Unbalanced binary tree
    TreeNode *root2 = new TreeNode(1,
                                   new TreeNode(2,
                                                new TreeNode(4),
                                                new TreeNode(5,
                                                             nullptr,
                                                             new TreeNode(6))),
                                   new TreeNode(3));
    cout << "Test case 2 is balanced: " << solution.isBalanced(root2) << endl; // Should print 0 (false)

    return 0;
}
