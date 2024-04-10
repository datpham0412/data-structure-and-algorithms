#include <iostream>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();

        TreeNode *temp = current->left;
        current->left = current->right;
        current->right = temp;

        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
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