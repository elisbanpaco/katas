/**
 * leetcode: 29-divide-two-integers
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determinar si el resultado debe ser negativo
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        long long result = 0;

        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            absDividend -= tempDivisor;
            result += multiple;
        }

        return isNegative ? -result : result;
    }
};

// MAIN PARA PRUEBAS
int main(){

    Solution sol;

    int result = sol.divide(10, 3);

    cout<<"Resultado: "<<result<<endl;

    return 0;
}
