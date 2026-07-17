/**
 * leetcode: 7-reverse-integer
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>

using namespace std;


#define INT_MAX 2147483647
#define INT_MIN -2147483648

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

// MAIN PARA PRUEBAS
int main(){
    Solution sol;
    int x = 123;
    int result = sol.reverse(x);
    cout << "El resultado es: " << result << endl;
    return 0;
}