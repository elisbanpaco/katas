/**
 * leetcode: 88-merge-sorted-array
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
        
        sort(nums1.begin(), nums1.end());
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    sol.merge(nums1, m, nums2, n);

    // Imprimir el vector
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }

    return 0;
}
