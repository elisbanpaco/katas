/**
 * leetcode: 53-maximum-subarray
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int resultado = sol.maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << resultado << endl;

    return 0;
}
