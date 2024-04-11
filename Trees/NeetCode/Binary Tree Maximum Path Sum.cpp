#include <iostream>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int maxPath = INT_MIN;
        dfs(root, &maxPath);
        return maxPath;
    }

private:
    int dfs(TreeNode *root, int *maxPath)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = dfs(root->left, maxPath);
        left = max(left, 0);
        int right = dfs(root->right, maxPath);
        right = max(right, 0);

        int currentPath = root->val + left + right;
        *maxPath = max(*maxPath, currentPath);

        return root->val + max(left, right);
    }
};

int main()
{
    // Create a binary tree with all negative values
    //       -10
    //       / \
    //     -20 -30
    //     /   / \
    //   -40 -50 -60
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(-20);
    root->right = new TreeNode(-30);
    root->left->left = new TreeNode(-40);
    root->right->left = new TreeNode(-50);
    root->right->right = new TreeNode(-60);

    Solution solution;
    cout << "Maximum Path Sum: " << solution.maxPathSum(root) << endl;

    // Cleanup
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
