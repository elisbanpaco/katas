/**
 * leetcode: 145-binary-tree-postorder-traversal
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
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
    
private:
    // Función auxiliar para realizar la recursividad
    void traverse(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        
        traverse(node->left, result);   // Izquierda
        traverse(node->right, result);  // Derecha
        result.push_back(node->val);    // Raíz
    }
};

// MAIN PARA PRUEBAS
int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);


    Solution solution;
    vector<int> result = solution.postorderTraversal(root);


    cout << "Resultado: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}