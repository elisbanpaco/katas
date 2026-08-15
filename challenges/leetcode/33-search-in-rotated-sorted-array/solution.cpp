/**
 * leetcode: 33-search-in-rotated-sorted-array
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

// MAIN PARA PRUEBAS
int main(){
    Solution sol;

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    int result = sol.search(nums, target);
    cout << "El Indice es: " << result << endl;

    return 0;
}
