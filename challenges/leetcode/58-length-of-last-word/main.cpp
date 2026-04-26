/**
 * leetcode: 58-length-of-last-word
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {

        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (count > 0)
                {
                    break;
                }
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    int result = sol.lengthOfLastWord("Hello luffy  ");
    cout << "La longitud de la ultima palabra es: " << result << endl;
    return 0;
}
