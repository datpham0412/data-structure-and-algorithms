#include <iostream>
#include <vector>
#include <algorithm> // For std::find

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
            return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);
        auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + mid);
        vector<int> rightPreorder(preorder.begin() + 1 + mid, preorder.end());

        vector<int> leftInorder(inorder.begin(), inorder.begin() + mid);
        vector<int> rightInorder(inorder.begin() + mid + 1, inorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};

void printInorder(TreeNode *node)
{
    if (node == nullptr)
        return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution solution;
    TreeNode *root = solution.buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root); // This should print: 9 3 15 20 7
    cout << endl;

    // Cleanup - Manual deallocation for demonstration purposes
    // In a real application, consider using smart pointers or container classes for automatic memory management
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
