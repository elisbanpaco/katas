/**
 * leetcode: 59-spiral-matrix-ii
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int num = 1;

        while (left <= right && top <= bottom) {
            // Fill top row
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            top++;

            // Fill right column
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--;

            // Fill bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = num++;
                }
                bottom--;
            }

            // Fill left column
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }

        return matrix;
    }
};

// MAIN PARA PRUEBAS
int main(){
    Solution sol;

    vector<vector<int>> result = sol.generateMatrix(3);

    for (const auto& row : result) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
