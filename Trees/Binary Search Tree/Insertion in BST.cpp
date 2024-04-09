// Time Complexity:

// The worst-case time complexity of insert operations is O(h) where h is the height of the Binary Search Tree.
// In the worst case, we may have to travel from the root to the deepest leaf node. The height of a skewed tree
// may become n and the time complexity of insertion operation may become O(n).
// Auxiliary Space: The auxiliary space complexity of insertion into a binary search tree is O(1)
#include <iostream>

using namespace std;

class BST
{
    struct Node
    {
        int val;
        Node *left;
        Node *right;
        Node(int value) : val(value), left(nullptr), right(nullptr) {}
    };
    Node *root;
    Node *insertNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }
        if (value < node->val)
        {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->val)
        {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

public:
    BST() : root(nullptr) {}
    void insert(int value)
    {
        root = insertNode(root, value);
    }
    void inorderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorderTraversal(node->left);
        cout << node->val << " ";
        inorderTraversal(node->right);
    }
    void display()
    {
        cout << "Inorder traversal of the given tree: ";
        inorderTraversal(root);
        cout << endl;
    }
};

int main()
{
    BST *binarySearchTree = new BST();
    binarySearchTree->insert(50);
    binarySearchTree->insert(30);
    binarySearchTree->insert(20);
    binarySearchTree->insert(40);
    binarySearchTree->insert(70);
    binarySearchTree->insert(60);
    binarySearchTree->insert(80);

    binarySearchTree->display();
    return 0;
}