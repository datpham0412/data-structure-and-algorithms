#include <iostream>

using namespace std;

class BST
{
    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int value) : data(value), left(NULL), right(NULL) {}
    };

    Node *root;
    Node *insert(Node *node, int value)
    {
        // Base case: If the tree is empty, return a new node
        if (node == NULL)
        {
            return new Node(value);
        }

        // Otherwise, recur down the tree
        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }

        // Return the (unchanged) node pointer
        return node;
    }

public:
    BST() : root(NULL) {}

    void insert(int value)
    {
        root = insert(root, value);
    }

    // Function to do inorder traversal of BST
    void inorderTraversal(Node *node)
    {
        if (node != NULL)
        {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void display()
    {
        inorderTraversal(root);
        cout << endl;
    }
};

int main()
{
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal of the given tree: \n";
    bst.display();

    return 0;
}