/**
 * leetcode: 69-sqrtx
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
        {
            return x;
        }

        int left = 1;
        int right = x;

        while (left <= right)
        {
            long mid = left + (right - left) / 2;

            if (mid * mid == x)
            {
                return (int)mid;
            }
            else if (mid * mid < x)
            {
                left = (int)mid + 1;
            }
            else
            {
                right = (int)mid - 1;
            }
        }
        return right;
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    int x = 2147395599;

    int result = sol.mySqrt(x);

    cout << "Resultado de la raiz cuadrada: " << result << endl;

    return 0;
}
