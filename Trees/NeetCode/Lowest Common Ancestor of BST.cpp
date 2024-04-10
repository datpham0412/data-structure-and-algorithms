#include <iostream>

// Definition for a binary tree node.
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            return root;
        }
    }
};

int main(int argc, char **argv)
{
    // Create a sample binary search tree
    //       6
    //      / \
    //     2   8
    //    / \ / \
    //   0  4 7  9
    //     / \
    //    3   5
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    Solution solution;

    // Test case 1
    TreeNode *p = root->left;  // Node with value 2
    TreeNode *q = root->right; // Node with value 8
    TreeNode *lca1 = solution.lowestCommonAncestor(root, p, q);
    std::cout << "LCA of " << p->val << " and " << q->val << " is: " << lca1->val << std::endl;

    // Test case 2
    p = root->left;        // Node with value 2
    q = root->left->right; // Node with value 4
    TreeNode *lca2 = solution.lowestCommonAncestor(root, p, q);
    std::cout << "LCA of " << p->val << " and " << q->val << " is: " << lca2->val << std::endl;

    // Clean up the tree
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
