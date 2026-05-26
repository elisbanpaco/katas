/**
 * leetcode: 136-single-number
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int single = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            single ^= nums[i];
        }
        return single;
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    vector<int> nums = {4, 1, 2, 1, 2};

    int result = sol.singleNumber(nums);

    cout << "El resultado es: " << result << endl;

    return 0;
}
