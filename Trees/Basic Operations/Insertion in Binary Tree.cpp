// Insertion in binary tree in level order
// Time : O(V) where V is the number of nodes
// Space : O(B) where B is the width of the tree and in the worst case we need to hold all vertices of a level in the queue

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

TreeNode *insertNode(TreeNode *node, int value)
{
    // If the root is empty
    if (node == nullptr)
    {
        node = new TreeNode(value);
        return node;
    }
    // The idea is to do an iterative level order traversal of the given tree using queue.
    // If we find a node whose left child is empty, we make a new key as the left child of the node.
    // Else if we find a node whose right child is empty, we make the new key as the right child.
    // We keep traversing the tree until we find a node whose either left or right child is empty.
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
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(11);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(7);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(8);

    cout << "Inorder traversal before insertion: ";
    inorderTraversal(root);
    cout << endl;

    insertNode(root, 12);
    cout << "Inorder traversal after insertion: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}
