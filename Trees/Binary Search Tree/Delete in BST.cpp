// Time Complexity: O(h), where h is the height of the BST.
// Auxiliary Space: O(n).

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
    Node *deleteNode(Node *node, int value)
    {
        // Base case
        if (node == nullptr)
        {
            return node;
        }
        // Recursive calls for ancestors of node to be deleted
        if (value < node->val)
        {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->val)
        {
            node->right = deleteNode(node->right, value);
        }
        else
        {
            // Node with only one child or no child
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            // Node with two childer: Get the inorder successor (smallest in the right subtree)
            Node *temp = minValueNode(node->right);
            // Copy the inorder successor's content to this node
            node->val = temp->val;
            // Delete the inorder successor
            node->right = deleteNode(node->right, temp->val);
        }
        return node;
    }
    // Helper function to find the node with the minimum value (leftmost leaf node)
    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
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

public:
    BST() : root(nullptr) {}
    void insert(int value)
    {
        root = insertNode(root, value);
    }
    void deleteValue(int value)
    {
        root = deleteNode(root, value);
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
    cout << "Initial BST: ";
    binarySearchTree->display();

    binarySearchTree->deleteValue(50);
    cout << "\nAfter deleting: ";
    binarySearchTree->display();
    return 0;
}