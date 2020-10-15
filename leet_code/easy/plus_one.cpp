/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 0 ms - Beats 100.00% of submissions
 * Memory: 9.1 MB - Beats 100.00% of submissions
 * Data Structures:
 * Algorithms:
 * Other:
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); it++)
        {
            // Starting from last digit element,
            // if the digit element is not 9,
            // increment value by 1 and return answer.
            if (*it != 9)
            {
                // IMPORTANT: Use pre-increment operator for derefenced pointer values!
                ++*it;
                return digits;
            }
            // Digit element is 9, so replace with 0
            // and iterate backwards to previous digit.
            else
            {
                *it = 0;
            }
            
        }
        
        // If first digit element is 9
        // and was replaced with 0,
        // append 1 to the integer.
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};
