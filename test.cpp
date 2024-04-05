#include <iostream>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode *left, TreeNode *right) : val(value), left(left), right(right) {}
};

int maxDepth(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        return (lDepth > rDepth) ? (lDepth + 1) : (rDepth + 1);
    }
}

TreeNode *insertNode(TreeNode *node, int value)
{
    if (node == nullptr)
    {
        node = new TreeNode(value);
        return node;
    }
    queue<TreeNode *> q;
    q.push(node);
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        else
        {
            current->left = new TreeNode(value);
            return node;
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
        else
        {
            current->right = new TreeNode(value);
            return node;
        }
    }
}

void inorderTraversal(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    inorderTraversal(node->left);
    cout << node->val << " ";
    inorderTraversal(node->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    cout << "Tree before insert: ";
    inorderTraversal(root);
    insertNode(root, 7);
    insertNode(root, 8);
    insertNode(root, 9);
    insertNode(root, 10);

    cout << "Tree after insert: ";
    inorderTraversal(root);
    cout << "Max depth of tree is " << maxDepth(root);
    delete root;
    return 0;
}