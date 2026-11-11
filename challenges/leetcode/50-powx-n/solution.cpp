/**
 * leetcode: 50-powx-n
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        if (N == 0) return 1.0;

        bool negativo = N < 0;
        if (negativo) N = -N;

        double resultado = 1.0;

        while (N > 0) {
            if (N % 2 == 1) {
                resultado *= x;
            }

            x *= x;
            N /= 2;
        }

        return negativo ? 1.0 / resultado : resultado;
    }
};

int main(){
    double x = 2.0;
    int n = 10;
    Solution sol;
    double result = sol.myPow(x, n);
    cout << "Result of " << x << "^" << n << " is: "<< result << endl;

    return 0;
}
