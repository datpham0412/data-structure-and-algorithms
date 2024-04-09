#include <iostream>
#include <stack>
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
void iterativeDFS(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    stack<TreeNode *> stackNode;
    stackNode.push(node);
    while (!stackNode.empty())
    {
        TreeNode *current = stackNode.top();
        stackNode.pop();
        cout << current->val << " ";
        if (current->right != nullptr)
        {
            stackNode.push(current->right);
        }
        if (current->left != nullptr)
        {
            stackNode.push(current->left);
        }
    }
}
int main(int argc, char **argv)
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << "Iterative DFS: ";
    iterativeDFS(root);
    return 0;
}