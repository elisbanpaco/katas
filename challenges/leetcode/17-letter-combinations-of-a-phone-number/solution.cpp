/**
 * leetcode: 17-letter-combinations-of-a-phone-number
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string combination = "";
        backtrack(digits, 0, combination, result);
        return result;
    }

    void backtrack(string digits, int index, string combination, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(combination);
            return;
        }
        int digit = digits[index] - '0';
        string letters = keypad[digit];
        for (char letter : letters) {
            backtrack(digits, index + 1, combination + letter, result);
        }
    }
};

// MAIN PARA PRUEBAS
int main(){
    Solution sol;

    vector<string> result = sol.letterCombinations("23");

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
