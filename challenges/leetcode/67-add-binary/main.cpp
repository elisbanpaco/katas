/**
 * leetcode: 67-add-binary
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <algorithm> 
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "";
        result.reserve(max(a.size(), b.size()) + 1);
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry > 0)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += a[i] - '0';
            }
            if (j >= 0)
            {
                sum += b[j] - '0';
            }
            carry = sum / 2;
            // result = to_string(sum % 2) + result;
            result.push_back((sum % 2) + '0');
            i--;
            j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }

};

int main()
{
    Solution sol;

    string result = sol.addBinary("1010", "1011");
    cout << "El resultado es: " << result << endl;
    return 0;
}
