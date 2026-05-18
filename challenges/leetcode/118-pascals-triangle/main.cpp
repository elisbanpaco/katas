/**
 * leetcode: 118-pascals-triangle
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++)
            {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    vector<vector<int>> result;

    int numRows = 5;

    result = sol.generate(numRows);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
