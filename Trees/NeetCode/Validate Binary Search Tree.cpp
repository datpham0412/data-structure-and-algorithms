#include <iostream>
#include <climits>

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
// Pass by pointer
class Solution1
{
public:
    bool isValidBST(TreeNode *root)
    {
        long minVal = LONG_MIN;
        long maxVal = LONG_MAX;
        return isHelper(root, &minVal, &maxVal);
    }

private:
    bool isHelper(TreeNode *root, long *left, long *right)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val < *right && root->val > *left)
        {
            long rootVal = root->val;
            return isHelper(root->left, left, &rootVal) && isHelper(root->right, &rootVal, right);
        }
        return false;
    }
};
// Pass by reference:
class Solution2
{
public:
    bool isValidBST(TreeNode *root)
    {
        return isHelper(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isHelper(TreeNode *root, long left, long right)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val < right && root->val > left)
        {
            return isHelper(root->left, left, root->val) && isHelper(root->right, root->val, right);
        }
        return false;
    }
};
int main()
{
    // Case 1: True BST
    TreeNode *root1 = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    // Case 2: Not a BST
    TreeNode *root2 = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));

    Solution1 solution;
    cout << "Case 1 - Is valid BST? " << (solution.isValidBST(root1) ? "True" : "False") << endl;
    cout << "Case 2 - Is valid BST? " << (solution.isValidBST(root2) ? "True" : "False") << endl;

    // Clean up
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left;
    delete root2->right->left;
    delete root2->right->right;
    delete root2->right;
    delete root2;

    return 0;
}
