/**
 * leetcode: 8-string-to-integer-atoi
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
    int myAtoi(string s) {
        int sign = 1;
        int result = 0;
        int i = 0;

        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }

        while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};

// MAIN PARA PRUEBAS 
int main(){

    Solution sol;

    string s = "0-1";

    int result = sol.myAtoi(s);

    cout<<"Resultado: "<<result<<endl;

    return 0;
}
