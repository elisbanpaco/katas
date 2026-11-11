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
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double result = 1.0;
        double current_product = x;
        
        while (N > 0) {
            if (N % 2 == 1) {
                result *= current_product;
            }
            current_product *= current_product;
            N /= 2;
        }
        
        return result;
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
