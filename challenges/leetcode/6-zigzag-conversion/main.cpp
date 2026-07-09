/**
 * leetcode: 6-zigzag-conversion
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        string result;
        int n = s.length();
        int cycleLength = 2 * numRows - 2;
        
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < n; j += cycleLength) {
                result += s[j];
                if (i > 0 && i < numRows - 1 && j + cycleLength - 2 * i < n) {
                    result += s[j + cycleLength - 2 * i];
                }
            }
        }
        
        return result;
        
    }
};

// MAIN PARA PRUEBAS
int main() {
    string s = "PAYPALISHIRING";  
    int numRows = 3;

    Solution sol;
    string result = sol.convert(s, numRows);
    cout << "El resultado es: " << result << endl;

    return 0;
}
