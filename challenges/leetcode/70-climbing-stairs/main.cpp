/**
 * leetcode: 70-climbing-stairs
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }

        int primero = 1, segundo = 2, actual;

        for (int i = 3; i <= n; i++)
        {
            actual = primero + segundo;
            primero = segundo;
            segundo = actual;
        }
        
        return actual;
    }
};

// MAIN DE PRUEBAS
int main()
{
    Solution sol;

    int result = sol.climbStairs(2);
    cout << "Result: " << result << endl;
    return 0;
}
