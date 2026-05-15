/**
 * leetcode: 111-minimum-depth-of-binary-tree
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        if (root->left == nullptr)
        {
            return 1 + minDepth(root->right);
        }

        if (root->right == nullptr)
        {
            return 1 + minDepth(root->left);
        }

        return 1 + min(minDepth(root->left), minDepth(root->right));
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

    int result = sol.minDepth(root);
    cout << "Result: " << result << endl;

    return 0;
}
