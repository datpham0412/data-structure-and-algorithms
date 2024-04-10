// C++ program to find height of tree
#include <iostream>
#include <queue>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

/* Compute the "maxDepth" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *current = q.front();
            q.pop();
            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
        depth++;
    }
    return depth;
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
TreeNode *newNode(int data)
{
    TreeNode *Node = new TreeNode();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

// Driver code
int main()
{
    TreeNode *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(6);

    cout << "Height of tree is " << maxDepth(root);
    return 0;
}
