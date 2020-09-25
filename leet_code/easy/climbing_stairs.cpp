/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 0 ms - Beats 100.00% of submissions
 * Memory:  6.1 MB - Beats 46.91% of submissions
 * Data Structures:
 * Algorithms: Dynamic Programming (Tabulation)
 * Other: 
 */

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        else
        {
            vector<int> dp(n, 0);
            // 1 step.
            dp[0] = 1;
            // 2 steps.
            dp[1] = 2;
            // The remaining steps of n steps.
            for (int i = 2; i <= n - 1; i++)
            {
                dp[i] = dp[i-1] + dp[i-2];
            }
            return dp[n-1];
        }
    }
};

