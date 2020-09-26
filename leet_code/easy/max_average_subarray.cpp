/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 176 ms - Beats 61.41% of submissions
 * Memory: 16.8 MB - Beats 33.33% of submissions
 * Data Structures:
 * Algorithms: Sliding Window
 * Other:
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_average;
        double max_sum = 0, current_sum = 0;
        for (int i = 0; i < k; ++i)
        {
            max_sum += nums[i];
        }
        current_sum = max_sum;
        for (int i = k; i < nums.size(); ++i)
        {
            current_sum += nums[i] - nums[i - k];
            max_sum = std::max(max_sum, current_sum);
        }
        max_average = max_sum / k;
        return max_average;
    }
};

