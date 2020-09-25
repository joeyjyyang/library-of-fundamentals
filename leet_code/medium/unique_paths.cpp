/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 0 ms - Beats 100.0% of submissions
 * Memory: 6.7 MB - Beats 7.59% of submissions
 * Data Structures:
 * Algorithms: Dynamic Programming (Tabulation)
 * Other: Matrices (2D Vector)
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Dynamic programming matrix (to represent grid),
        // with m rows and n columns full of 0's.
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        // Populate all columns of first row (the first row) 
        // with 1's, since there is only 1 way to reach 
        // any cell (from left to right) in the first row.
        for (int column = 0; column < n; column++)
        {
            dp[0][column] = 1;
        }
        
        // Populate all rows of first column (the first column) 
        // with 1's, since there is only 1 way to reach 
        // any cell (from top to bottom) in the first column.
        for (int row = 0; row < m; row++)
        {
            dp[row][0] = 1;
        }
        
        // Iterate through remaining unpopulated cells
        // and determine number of unique paths by adding values 
        // from 2 cells: 1 above and 1 to the left.
        for (int row = 1; row < m; row++)
        {
            for (int column = 1; column < n; column++)
            {
                dp[row][column] = dp[row - 1][column] + dp[row][column - 1];
            }
        }
        // The number of unique paths is the accumulated value
        // in the final, bottom-right cell.
        return dp[m - 1][n - 1];
    }
};
