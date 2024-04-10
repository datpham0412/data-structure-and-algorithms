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
};

TreeNode *invertTree(TreeNode *root)
{
    // Base case:
    if (root == nullptr)
    {
        return nullptr;
    }
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);
    return root;
}

void BFSTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        cout << current->val << " ";
        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
}
int main(int argc, char **argv)
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    cout << "Original tree: ";
    BFSTraversal(root);
    invertTree(root);
    cout << "Inverted tree: ";
    BFSTraversal(root);
    delete root;
    return 0;
}