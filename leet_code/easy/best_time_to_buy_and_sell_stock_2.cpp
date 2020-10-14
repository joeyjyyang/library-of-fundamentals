/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 12 ms - Beats 68.11% of submissions
 * Memory: 13.4 MB - Beats 100.00% of submissions
 * Data Structures:
 * Algorithms:
 * Other:
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_profit = 0;
        int current_price, previous_price;
        // Iterate through prices, starting from second element (index 1).
        for (int i = 1; i < prices.size(); i++)
        {
            current_price = prices[i];
            previous_price = prices[i-1];
            // If current price is greater than previous price (peak > valley).
            if (current_price > previous_price)
            {
                // Add difference (profit) to total profit.
                total_profit += current_price - previous_price;
            }
        }
        return total_profit;
    }
};

