/**
 * leetcode: 34-find-first-and-last-position-of-element-in-sorted-array
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result = {-1, -1};

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                result[0] = mid;
                right = mid - 1;
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

        left = 0;
        right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                result[1] = mid;
                left = mid + 1;
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

        return result;
    }
};

// MAIN PARA PRUEBAS 
int main(){

    Solution sol;

    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> result = sol.searchRange(nums, target);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
