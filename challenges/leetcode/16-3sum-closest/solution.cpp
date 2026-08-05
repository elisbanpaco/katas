/**
 * leetcode: 16-3sum-closest
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int result = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    return sum;
                }
                if (abs(sum - target) < abs(result - target)) {
                    result = sum;
                }
            }
        }
        return result;
    }
};

// MAIN PARA PRUEBAS
int main(){
    Solution sol;

    vector<int> nums = {-1,2,1,-4};
    int target = 1;

    int result = sol.threeSumClosest(nums, target);

    cout << "El resultado es: " << result << endl;

    return 0;
}
