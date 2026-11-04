/**
 * leetcode: 43-multiply-strings
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        string result(len1 + len2, '0');
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = (result[i + j + 1] - '0') + mul;
                result[i + j + 1] = (sum % 10) + '0';
                result[i + j] += (sum / 10);
            }
        }

        // Remove leading zeros
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        if (start == result.size()) {
            result = "0";
        } else {
            result = result.substr(start);
        }

        return result;
    }
};

int main(){
    string num1 = "123";
    string num2 = "456";
    Solution sol;
    string result = sol.multiply(num1, num2);
    cout << "Result: " << result << endl;


    return 0;
}
