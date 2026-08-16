/**
 * leetcode: 38-count-and-say
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        } else {
            string prev = countAndSay(n - 1);
            string result = "";
            int count = 1;
            for (int i = 1; i < prev.length(); i++) {
                if (prev[i] == prev[i - 1]) {
                    count++;
                } else {
                    result += to_string(count) + prev[i - 1];
                    count = 1;
                }
            }
            result += to_string(count) + prev[prev.length() - 1];
            return result;
        } 
    }
};

// MAIN PARA PRUEBAS
int main(){
    Solution sol;

    string result = sol.countAndSay(1);
    cout << "El resultado es: " << result << endl;

    return 0;
}
