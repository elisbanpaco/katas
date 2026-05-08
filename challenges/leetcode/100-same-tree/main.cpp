/**
 * leetcode: 100-same-tree
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        if (p == nullptr || q == nullptr)
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);
    p->left->right = new TreeNode(5);
    p->right->left = new TreeNode(6);
    p->right->right = new TreeNode(7);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    q->left->left = new TreeNode(4);
    q->left->right = new TreeNode(5);
    q->right->left = new TreeNode(6);
    q->right->right = new TreeNode(7);

    bool result = sol.isSameTree(p, q);

    cout << "Result: " << result << endl;

    return 0;
}
