/**
 * leetcode: 31-next-permutation
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
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                int j = nums.size() - 1;
                while (nums[j] <= nums[i]) {
                    j--;
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());

    }
};

// MAIN PARA PRUEBAS
int main(){
    vector<int> nums = {1,2,3};
    Solution sol;

    sol.nextPermutation(nums);

    cout<<"El resultado es: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;


    return 0;
}
