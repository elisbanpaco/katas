/**
 * leetcode: 35-search-insert-position
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;

    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    vector<int> nums = {1, 3, 5, 6};
    int target = 8;

    int result = sol.searchInsert(nums, target);
    cout << "El Indice es: " << result << endl;

    return 0;
}
