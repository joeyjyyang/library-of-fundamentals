/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 4 ms - Beats 52.76% of submissions
 * Memory: 8.2 MB - Beats 100.00% of submissions
 * Data Structures:
 * Algorithms: Dynamic Porgramming (Tabulation)
 * Other: 
 */

class Solution {
public:
    int rob(vector<int>& nums) {        
        int n = nums.size();
        
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return nums[0];
        }
        else if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        else 
        {
            // DP array to track max money at each house (index).
            vector<int> dp(n);
            dp[0] = nums[0];
            // At house 2 (index 1), choose whether or not to take money.
            dp[1] = max(nums[0], nums[1]);
            // Begin iterating through rest of nums array.
            for (int i = 2; i < n; i++)
            {
                // Max money at current index is either
                // the money at current index plus accumulated money 
                // 2 houses before (choose to rob current house),
                // OR the accumulated money 1 house before (choose not 
                // to rob current house).
                dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
            }
            // Final index in DP array is the maximum money reward possible.
            return dp[n - 1];
        }
    }
};
