#include <iostream>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    bool isSame(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
        {
            return true;
        }
        if (root == nullptr || subRoot == nullptr)
        {
            return false;
        }
        if (root->val != subRoot->val)
        {
            return false;
        }
        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (isSame(root, subRoot))
        {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main()
{
    // Test case 1: Should return true
    TreeNode *root1 = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2)), new TreeNode(5));
    TreeNode *subRoot1 = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    Solution solution;
    std::cout << "Test case 1: " << (solution.isSubtree(root1, subRoot1) ? "true" : "false") << std::endl;

    // Clean up
    delete root1->left->left;  // Node 1
    delete root1->left->right; // Node 2
    delete root1->left;        // Node 4
    delete root1->right;       // Node 5
    delete root1;              // Node 3
    delete subRoot1->left;     // Node 1
    delete subRoot1->right;    // Node 2
    delete subRoot1;           // Node 4

    // Test case 2: Should return false
    TreeNode *root2 = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2, nullptr, new TreeNode(0))), new TreeNode(5));
    TreeNode *subRoot2 = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    std::cout << "Test case 2: " << (solution.isSubtree(root2, subRoot2) ? "true" : "false") << std::endl;

    // Clean up
    delete root2->left->left;         // Node 1
    delete root2->left->right->right; // Node 0
    delete root2->left->right;        // Node 2
    delete root2->left;               // Node 4
    delete root2->right;              // Node 5
    delete root2;                     // Node 3
    delete subRoot2->left;            // Node 1
    delete subRoot2->right;           // Node 2
    delete subRoot2;                  // Node 4

    return 0;
}
