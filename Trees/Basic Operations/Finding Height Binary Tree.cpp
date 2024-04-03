// C++ program to find height of tree
#include <iostream>
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
int maxDepth(TreeNode *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
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

// Trace of Recursive Calls

// 1) maxDepth(1)
// - Needs maxDepth(2) and maxDepth(3)

// 2) maxDepth(2)
//  - Needs maxDepth(4) and maxDepth(5)

// 3) maxDepth(4)
// - node == NULL? No, but both children are NULL.
// - Returns 0 + 1 = 1

// 4) maxDepth(5)
// - Needs maxDepth(NULL) (left child) and maxDepth(6) (right child)
// - maxDepth(NULL) returns 0 (since node == NULL)
// - maxDepth(6) needs to be evaluated

// 5) maxDepth(6)
// - node == NULL? No, but both children are NULL.
// - Returns 0 + 1 = 1

// 6) Back to maxDepth(5)
// - Compares left 0 and right 1, chooses 1
// - Returns 1 + 1 = 2

// 7) Back to maxDepth(2)
// - Compares maxDepth(4) 1 and maxDepth(5) 2, chooses 2
// - Returns 2 + 1 = 3

// 8) maxDepth(3)
// - node == NULL? No, but both children are NULL.
// - Returns 0 + 1 = 1

// 9) Finally, back to maxDepth(1)
// - Compares maxDepth(2) 3 and maxDepth(3) 1, chooses 3
// - Returns 3 + 1 = 4