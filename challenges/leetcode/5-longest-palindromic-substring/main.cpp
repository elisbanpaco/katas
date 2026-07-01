/**
 * leetcode: 5-longest-palindromic-substring
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:

    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLength = 0;
        
        for (int i = 0; i < s.length(); i++) {

            int len1 = expandAroundCenter(s, i, i);

            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);

            if (len > maxLength) {
                maxLength = len;

                start = i - (len - 1) / 2;
            }
        }
        

        return s.substr(start, maxLength);
    }
};

// MAIN PARA PRUEBAS
int main() {
    Solution solver;
    
    // Caso de prueba 1
    string ejemplo1 = "babad";
    cout << "Entrada: " << ejemplo1 << " -> Salida: " << solver.longestPalindrome(ejemplo1) << endl;
    
    // Caso de prueba 2
    string ejemplo2 = "cbbd";
    cout << "Entrada: " << ejemplo2 << " -> Salida: " << solver.longestPalindrome(ejemplo2) << endl;
    
    return 0;
}