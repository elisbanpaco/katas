/**
 * leetcode: 36-valid-sudoku
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int val = board[r][c] - '1';
                int mask = 1 << val;
                int boxIdx = (r / 3) * 3 + (c / 3);

                if ((rows[r] & mask) || (cols[c] & mask) || (boxes[boxIdx] & mask)) {
                    return false;
                }

                rows[r] |= mask;
                cols[c] |= mask;
                boxes[boxIdx] |= mask;
            }
        }
        return true;
    }
};

// MAIN PARA PRUEBAS
int main(){
    Solution sol;

    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};

    cout << sol.isValidSudoku(board);

    return 0;
}
