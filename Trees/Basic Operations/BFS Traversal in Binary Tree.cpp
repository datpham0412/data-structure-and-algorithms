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
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

void BFSTraversal(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(node);
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
int main()
{
    TreeNode root(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left->left = new TreeNode(4);
    root.left->right = new TreeNode(5);
    root.left->left = new TreeNode(6);
    root.left->right = new TreeNode(7);
    cout << "Breadth First Search Traversal: ";
    BFSTraversal(&root);
    return 0;
}