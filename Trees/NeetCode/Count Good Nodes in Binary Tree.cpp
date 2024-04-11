/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
using namespace std;

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
    int goodNodes(TreeNode *root)
    {
        int result = 0;
        dfs(root, root->val, &result);
        return result;
    }

private:
    void dfs(TreeNode *root, int maxSoFar, int *result)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->val >= maxSoFar)
        {
            ++(*result);
        }
        dfs(root->left, max(maxSoFar, root->val), result);
        dfs(root->right, max(maxSoFar, root->val), result);
    }
};

int main()
{
    // Construct the binary tree from the test case [3,1,4,3,null,1,5]
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1, new TreeNode(3), nullptr);
    root->right = new TreeNode(4, new TreeNode(1), new TreeNode(5));

    Solution solution;
    cout << "Number of good nodes: " << solution.goodNodes(root) << endl;

    // Clean up the dynamically allocated nodes
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}