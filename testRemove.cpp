#include <iostream>
#include <cmath>
#include <algorithm>

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
        if (root == NULL)
        {
            height = -1;
            return true;
        }

        int left = 0;
        int right = 0;

        if (!dfs(root->left, left) || !dfs(root->right, right))
        {
            return false;
        }
        if (abs(left - right) > 1)
        {
            return false;
        }

        height = 1 + max(left, right);
        return true;
    }
};

int main()
{
    // Constructing the test case as a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    bool isBal = solution.isBalanced(root);
    if (isBal)
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }

    // Clean up the allocated nodes
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
