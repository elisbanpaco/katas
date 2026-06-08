/**
 * leetcode: 169-majority-element
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int major = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                major = nums[i];
                count = 1;
            }
            else if (nums[i] == major)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return major;
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int result = sol.majorityElement(nums);

    cout << "El resultado es: " << result << endl;
    return 0;
}
