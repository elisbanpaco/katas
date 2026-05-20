/**
 * leetcode: 121-best-time-to-buy-and-sell-stock
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = sol.maxProfit(prices);

    cout << "El resultado es: " << result << endl;

    return 0;
}
