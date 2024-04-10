#include <iostream>

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        if (p == nullptr || q == nullptr)
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    // Test case 1 (should return true): Two identical trees
    TreeNode *tree1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode *tree2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    Solution solution;
    std::cout << "Test case 1 (true case): " << (solution.isSameTree(tree1, tree2) == true ? "true" : "false") << std::endl;

    // Test case 2 (should return false): Two different trees
    TreeNode *tree3 = new TreeNode(1, new TreeNode(2), nullptr);
    TreeNode *tree4 = new TreeNode(1, nullptr, new TreeNode(2));
    std::cout << "Test case 2 (false case): " << (solution.isSameTree(tree3, tree4) == true ? "true" : "false") << std::endl;

    // Cleanup dynamically allocated memory
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;
    delete tree3->left;
    delete tree3;
    delete tree4->right;
    delete tree4;

    return 0;
}
