/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 4 ms - Beats 99.71% of submissions
 * Memory: 10 MB - Beats 56.40% of submissions
 * Data Structures:
 * Algorithms: Kadane's Algorithm, Dynamic Programming (Tabulation)
 * Other: Subarrays
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's Algorithm.
        
        // Start current max sum as first number element.
        int current_max_sum = nums[0];
        int total_max_sum = current_max_sum;
        
        // Begin iterating from second number.
        for (int i = 1; i < nums.size(); i++)
        {
            // Restart current max sum from current number,
            // or update current max sum to previous max sum 
            // plus current number.
            current_max_sum = max(nums[i], current_max_sum + nums[i]);
            
            // Update total max sum to current max sum.
            total_max_sum = max(current_max_sum, total_max_sum);
        }
        return total_max_sum;
    }
};
