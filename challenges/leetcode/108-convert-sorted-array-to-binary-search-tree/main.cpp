/**
 * leetcode: 108-convert-sorted-array-to-binary-search-tree
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {

        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }

    void ImprimirArbol(TreeNode *root)
    {
        if (root == nullptr)
        {
            cout << "null ";
            return;
        }
        cout << root->val << " ";
        ImprimirArbol(root->left);
        ImprimirArbol(root->right);
    }
};

// MAIN PARA PRUEBAS
int main()
{
    vector<int> nums = {1, 3};

    Solution sol;
    TreeNode *result = sol.sortedArrayToBST(
        nums);

    sol.ImprimirArbol(result);

    return 0;
}
