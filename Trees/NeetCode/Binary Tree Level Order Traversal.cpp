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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> curr;
            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode *current = q.front();
                q.pop();
                curr.push_back(current->val);
                if (current->left != nullptr)
                {
                    q.push(current->left);
                }
                if (current->right != nullptr)
                {
                    q.push(current->right);
                }
            }
            result.push_back(curr);
        }
        return result;
    }
};

int main()
{
    // Construct the tree as per the input: [3,9,20,null,null,15,7]
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Create a Solution object and use it to perform level order traversal
    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);

    // Output the result
    cout << "[";
    for (const auto &level : result)
    {
        cout << "[";
        for (size_t i = 0; i < level.size(); ++i)
        {
            cout << level[i];
            if (i < level.size() - 1)
            {
                cout << ",";
            }
        }
        cout << "]";
        if (&level != &result.back())
        {
            cout << ",";
        }
    }
    cout << "]" << endl;

    // Clean up dynamically allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
