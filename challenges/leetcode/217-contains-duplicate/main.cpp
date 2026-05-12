/**
 * leetcode: 217-contains-duplicate
 * Language: C++
 * Created with Code Forge
 */

#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        
        for (int num : nums) {
            // Si el número ya está en el set, encontramos un duplicado
            if (seen.find(num) != seen.end()) {
                return true;
            }
            // Si no está, lo agregamos al set
            seen.insert(num);
        }
        
        // Si terminamos de recorrer el arreglo, no hay duplicados
        return false;
    }
};

int main() {


    return 0;
}
