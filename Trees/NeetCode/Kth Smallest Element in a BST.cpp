#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int result = 0;
        inorder(root, k, result);
        return result;
    }

private:
    void inorder(TreeNode *root, int &k, int &result)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, k, result);
        --k;
        if (k == 0)
        {
            result = root->val;
            return;
        }
        inorder(root->right, k, result);
    }
};

int main()
{
    // Test case 1: [3,1,4,null,2], k = 2
    TreeNode *root1 = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4));
    Solution sol;
    cout << "Test case 1 - kth smallest: " << sol.kthSmallest(root1, 2) << endl; // Expected output: 2

    // Clean up
    delete root1->left->right;
    delete root1->left;
    delete root1->right;
    delete root1;

    // Test case 2: [5,3,6,2,4,null,null,1], k = 3
    TreeNode *root2 = new TreeNode(5,
                                   new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)),
                                   new TreeNode(6));
    cout << "Test case 2 - kth smallest: " << sol.kthSmallest(root2, 3) << endl; // Expected output: 3
    TreeNode *root3 = new TreeNode(4,
                                   new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                                   new TreeNode(6, new TreeNode(5), new TreeNode(7)));
    cout << "Test case 3 - kth smallest: " << sol.kthSmallest(root3, 3) << endl; // Expected output: 3
    // Clean up
    delete root2->left->left->left;
    delete root2->left->left;
    delete root2->left->right;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
