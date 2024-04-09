// Time complexity: O(h), where h is the height of the BST.
// Auxiliary Space: O(h), where h is the height of the BST.
// This is because the maximum amount of space needed to store the recursion stack would be h.
#include <iostream>

using namespace std;

class BST
{
public:
    struct Node
    {
        int val;
        Node *left;
        Node *right;
        Node(int value) : val(value), left(nullptr), right(nullptr) {}
    };

private:
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
    Node *search(Node *node, int value)
    {
        // Base case: root is null or value is present at root
        if (node == nullptr || node->val == value)
        {
            return node;
        }
        // Value is greater than root's data
        if (node->val < value)
        {
            return search(node->right, value);
        }

        return search(node->left, value);
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
    bool search(int value)
    {
        Node *result = search(root, value);
        return result != nullptr;
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
    if (binarySearchTree->search(20))
    {
        cout << "20 found in the BST" << endl;
    }
    else
    {
        cout << "20 not found in the BST" << endl;
    }
    if (binarySearchTree->search(25))
    {
        cout << "25 found in the BST" << endl;
    }
    else
    {
        cout << "25 not found in the BST" << endl;
    }

    binarySearchTree->display();
    return 0;
}