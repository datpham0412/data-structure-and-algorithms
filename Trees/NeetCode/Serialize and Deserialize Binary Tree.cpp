#include <iostream>
#include <sstream>
#include <string>

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};
using namespace std;
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream out;
        encode(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return decode(in);
    }

private:
    void encode(TreeNode *root, ostringstream &out)
    {
        if (root == nullptr)
        {
            out << "N ";
            return;
        }
        out << root->val << " ";
        encode(root->left, out);
        encode(root->right, out);
    }
    TreeNode *decode(istringstream &in)
    {
        string value = "";
        in >> value;
        if (value == "N")
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(value));
        root->left = decode(in);
        root->right = decode(in);
        return root;
    }
};

void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << "NULL ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    // Construct the tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Instantiate Codec
    Codec ser, deser;

    // Serialize the tree
    std::string serialized = ser.serialize(root);
    std::cout << "Serialized tree: " << serialized << std::endl;

    // Deserialize the tree
    TreeNode *deserializedTree = deser.deserialize(serialized);
    std::cout << "Tree after deserialization (Pre-order): ";
    printTree(deserializedTree); // Print the tree to verify it's correct
    std::cout << std::endl;

    // Clean up memory - Ideally use smart pointers in real scenarios
    delete root->left->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}