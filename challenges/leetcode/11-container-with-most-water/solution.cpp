/**
 * leetcode: 11-container-with-most-water
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        
        while (left < right) {
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
        
    }
};

// MAIN PARA PRUEBAS
int main(){
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    int result = sol.maxArea(height);
    cout << "El resultado es: " << result << endl;

    return 0;
}
