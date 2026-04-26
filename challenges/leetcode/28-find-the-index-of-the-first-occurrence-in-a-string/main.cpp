/**
 * leetcode: 28-find-the-index-of-the-first-occurrence-in-a-string
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {

        char firtLetter = needle[0];
        int h_len = haystack.size();
        int n_len = needle.size();

        if (h_len < n_len)
        {
            return -1;
        }

        for (int i = 0; i <= h_len - n_len; i++)
        {
            if (haystack[i] == firtLetter)
            {
                if (haystack.substr(i, needle.size()) == needle)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    int result = sol.strStr("leetcode", "de");
    cout << "El Indice es: " << result << endl;
    return 0;
}
