#include <iostream>

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

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int result = 0;
        // wrong: result = dfs(root, result);
        dfs(root, result);
        return result;
    }

private:
    int dfs(TreeNode *root, int &result)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        result = max(result, left + right);
        return 1 + max(left, right);
    }
};

int main(int argc, char **argv)
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution solution = Solution();
    cout << "The diameter of the binary tree is " << solution.diameterOfBinaryTree(root) << endl;
    return 0;
}