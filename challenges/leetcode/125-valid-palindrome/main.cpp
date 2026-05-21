/**
 * leetcode: 125-valid-palindrome
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int inicio = 0;
        int fin = s.length() - 1;

        while (inicio < fin)
        {

            if (!isalnum(s[inicio]))
            {
                inicio++;
            }

            else if (!isalnum(s[fin]))
            {
                fin--;
            }

            else
            {
                if (tolower(s[inicio]) != tolower(s[fin]))
                {
                    return false;
                }
                inicio++;
                fin--;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;

    string s = "A man, a plan, a canal: Panama";
    bool result = sol.isPalindrome(s);
    cout << "El resultado es: " << result << endl;

    return 0;
}
