/**
 * leetcode: 12-integer-to-roman
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };
        
        string result = "";
        
        for (const auto& pair : romanMap) {
            while (num >= pair.first) {
                result += pair.second; 
                num -= pair.first;    
            }
        }
        
        return result;
    }
};


// MAIN PARA PRUEBAS
int main() {
    Solution solver;
    
    // Casos de prueba comunes de LeetCode
    int test1 = 3749;
    int test2 = 58;
    int test3 = 1994;
    
    cout << test1 << " en Romano es: " << solver.intToRoman(test1) << " (Esperado: MMMDCCXLIX)" << endl;
    cout << test2 << " en Romano es: " << solver.intToRoman(test2) << " (Esperado: LVIII)" << endl;
    cout << test3 << " en Romano es: " << solver.intToRoman(test3) << " (Esperado: MCMXCIV)" << endl;
    
    return 0;
}