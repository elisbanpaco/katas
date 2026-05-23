/**
 * leetcode: 144-binary-tree-preorder-traversal
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
using namespace std;

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traverse(root, result);
        return result;
    }
    void traverse(TreeNode *node, vector<int> &result)
    {
        if (node == nullptr)
        {
            return;
        }

        result.push_back(node->val);
        traverse(node->left, result);
        traverse(node->right, result);
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = sol.preorderTraversal(root);

    // Imprimir el vector
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
