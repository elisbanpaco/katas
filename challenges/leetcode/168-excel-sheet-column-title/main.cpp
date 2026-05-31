/**
 * leetcode: 168-excel-sheet-column-title
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string result = "";
        while (columnNumber > 0)
        {
            char letter = 'A' + (columnNumber - 1) % 26;
            result = letter + result;
            columnNumber = (columnNumber - 1) / 26;
        }
        return result;
    }
};
// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    string result = sol.convertToTitle(26);
    cout << "El resultado es: " << result << endl;

    return 0;
}
