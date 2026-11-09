/**
 * leetcode: 46-permutations
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, current, result);
        return result;
        
    }
private:
    void backtrack(const vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                current.push_back(nums[i]);
                backtrack(nums, used, current, result);
                current.pop_back();
                used[i] = false;
            }
        }
    }
};

int main(){
    vector<int> nums = {1, 2, 3};
    Solution sol;
    vector<vector<int>> result = sol.permute(nums);
    cout << "Result: " << endl;
    for (const auto& perm : result) {
        cout << "[";
        for (size_t i = 0; i < perm.size(); i++) {
            cout << perm[i];
            if (i < perm.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}
