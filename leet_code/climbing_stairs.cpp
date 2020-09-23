/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 0 ms - Beats 100.00% of submissions
 * Memory:  6.1 MB - Beats 46.91% of submissions
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
            vector<int> solutions(n, 0);
            // 1 step.
            solutions[0] = 1;
            // 2 steps.
            solutions[1] = 2;
            // The remaining steps of n steps.
            for (int i = 2; i <= n - 1; i++)
            {
                solutions[i] = solutions[i-1] + solutions[i-2];
            }
            return solutions[n-1];
        }
    }
};

