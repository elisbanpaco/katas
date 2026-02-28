/**
 * leetcode: reverse-integer
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int reverse(int x){
    int reversed = 0;

    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (reversed > INT_MAX/10 || (reversed == INT_MAX / 10 && pop > 7)) return 0;
        if (reversed < INT_MIN/10 || (reversed == INT_MIN / 10 && pop < -8)) return 0;
        reversed = reversed * 10 + pop;
    }
    return reversed;
}

int main() {
    int x = -120;

    cout<<reverse(x)<<endl;

    // cout << "Hello world !!! " << endl;
    return 0;
}
