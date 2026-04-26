/**
 * leetcode: 26-remove-duplicates-from-sorted-array
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        if (nums.size() == 0)
            return 0;

        int k = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            // nos preguntamos ¿Es el número actual diferente al anterior?
            if (nums[i] != nums[i - 1])
            {
                // Lo movemos a la posición donde toca escribir
                nums[k] = nums[i];
                // Aumentamos k porque ya encontramos un nuevo único
                k++;
            }
        }

        return k;
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int result = sol.removeDuplicates(nums);
    cout << "Nueva longitud del vector: " << result << endl;
    return 0;
}
