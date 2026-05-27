/**
 * leetcode: 171-excel-sheet-column-number
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int result = 0;

        for (int i = 0; i < columnTitle.length(); i++)
        {
            // Obtenemos el valor de la letra
            int valor_letra = columnTitle[i] - 'A' + 1;

            // Multiplicamos por la base 26 y sumamos
            result = result * 26 + valor_letra;
        }

        return result;
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    int result = sol.titleToNumber("FXSHRXW");
    cout << "El resultado es: " << result << endl;

    return 0;
}
