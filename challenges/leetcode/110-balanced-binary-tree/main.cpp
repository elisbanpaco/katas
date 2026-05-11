/**
 * leetcode: 110-balanced-binary-tree
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
    int checkHeight(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1)
            return -1;

        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        return checkHeight(root) != -1;
    }
};

// MAIN PARA PRUEBAS
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;

    bool result = sol.isBalanced(root);

    cout << "Result: " << result << endl;

    return 0;
}
