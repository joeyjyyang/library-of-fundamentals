/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 0 ms - Beats 100.00% of submissions
 * Memory: 6.8 MB - Beats 5.22% of submissions
 * Data Structures:
 * Algorithms: Dynamic Programming (Tabulation)
 * Other: Matrices
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows, vector<int>());
        if (numRows == 0)
        {
            return triangle;
        }
        // Add 1 to first row of triangle.
        triangle[0].push_back(1);
        // Iterate through remaining rows of triangle (matrix).
        for (int i = 1; i < numRows; i++)
        {
            // Push 1 to first column of each row.
            triangle[i].push_back(1);
            // Iterate through remaining columns of triangle,
            // starting from second column, ending at second last column.
            for (int j = 1; j < i; j++)
            {
                // Value at current index is equal to the sum of
                // two numbers above (in previous row).
                triangle[i].push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
            }
            // Push 1 to last column of each row.
            triangle[i].push_back(1);
        }
        return triangle;
    }
};

