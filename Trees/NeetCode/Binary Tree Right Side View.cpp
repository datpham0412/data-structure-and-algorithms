#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode *current = q.front();
                q.pop();
                if (i == 0)
                {
                    result.push_back(current->val);
                }
                if (current->right != nullptr)
                {
                    q.push(current->right);
                }
                if (current->left != nullptr)
                {
                    q.push(current->left);
                }
            }
        }
        return result;
    }
};

int main()
{
    // Construct the binary tree from the input [1,2,3,4,5,6,7]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Create a Solution object and get the right side view of the binary tree
    Solution solution;
    vector<int> rightView = solution.rightSideView(root);

    // Output the right side view
    cout << "Right side view: ";
    for (int val : rightView)
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the dynamically allocated nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
