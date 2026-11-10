/**
 * leetcode: 48-rotate-image
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution sol;
    sol.rotate(matrix);
    cout << "Rotated Matrix: " << endl;
    for (const auto& row : matrix) {
        cout << "[";
        for (size_t i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i < row.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
