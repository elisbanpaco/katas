/**
 * leetcode: 89-gray-code
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        for (int i = 0; i < n; i++)
        {
            int size = result.size();
            for (int j = size - 1; j >= 0; j--)
            {
                result.push_back(result[j] | (1 << i));
            }
        }
        return result;
    }
};

// MAIN PARA PRUEBAS
int main(){
    Solution sol;

    vector<int> result = sol.grayCode(2);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
