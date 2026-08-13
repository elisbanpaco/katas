/**
 * leetcode: 22-generate-parentheses
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> result;
        string combination = "";
        backtrack(n, 0, 0, combination, result);
        return result;
    }

    void backtrack(int n, int open, int close, string combination, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(combination);
            return;
        }
        if (open < n) {
            backtrack(n, open + 1, close, combination + "(", result);
        }
        if (close < open) {
            backtrack(n, open, close + 1, combination + ")", result);
        }
    }
};

// MAIN PARA PRUEBAS
int main(){

    Solution sol;

    vector<string> result = sol.generateParenthesis(3);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
