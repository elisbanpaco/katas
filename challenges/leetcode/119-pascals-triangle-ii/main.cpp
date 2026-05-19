/**
 * leetcode: 119-pascals-triangle-ii
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> row(rowIndex + 1, 1);

        for (int i = 1; i < rowIndex; i++)
        {
            for (int j = i; j > 0; j--)
            {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    vector<int> result = sol.getRow(3);

    // Imprimir el vector
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
