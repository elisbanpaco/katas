/**
 * leetcode: 27-remove-element
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.size() == 0)
            return 0;

        if (nums.size() == 1)
        {
            if (nums[0] == val)
                return 0;
            else
                return 1;
        }

        int k = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            // nos preguntamos ¿Es el número actual diferente al anterior?
            if (nums[i] != val)
            {
                // Lo movemos de la posición donde toca escribir
                nums[k] = nums[i];
                // Aumentamos k porque ya encontramos un nuevo único
                k++;
            }
        }

        return k;
    }
    // SOLO PARA PRUEBAS - IMPRIME EL VECTOR + VALOR DE K
    void printVector(vector<int> &nums, int val)
    {

        int k = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            // nos preguntamos ¿Es el número actual diferente al anterior?
            if (nums[i] != val)
            {
                // Lo movemos de la posición donde toca escribir
                nums[k] = nums[i];
                // Aumentamos k porque ya encontramos un nuevo único
                k++;
            }
        }


        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;

        cout<<"valor de k: "<<k<<endl;
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    // vector<int> nums = {3,2,2,3};
    // vector<int> nums = {3, 3};
    vector<int> nums = {0,1,2,2,3,0,4,2};

    int val = 2;

    // int result = sol.removeElement(nums, val);
    // cout << "Nueva longitud del vector: " << result << endl;


    sol.printVector(nums, val);
    return 0;
}
