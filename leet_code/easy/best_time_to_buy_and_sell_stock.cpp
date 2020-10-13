/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 8 ms - Beats 96.25% of submissions
 * Memory: 13.3 MB - Beats 100.00% of submissions
 * Data Structures:
 * Algorithms:
 * Other:
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy_price = INT_MAX;
        int max_profit = 0;
        for (vector<int>::iterator it = prices.begin(); it != prices.end(); it++)
        {
            // If new price element's value is less than 
            // current min buy price, update.
            if (*it < min_buy_price)
            {
                min_buy_price = *it;
            }
            // Keep current min buy price.
            else
            {
                // Calculate current profit based on current min buy price.
                int current_profit = *it - min_buy_price;
                if (current_profit > max_profit)
                {
                    max_profit = current_profit;
                }
            }
        }
        return max_profit;
    }
};
