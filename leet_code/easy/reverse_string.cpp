/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 32 ms - Beats 97.23% of submissions
 * Memory: 23.3 MB - Beats 55.54% of submissions
 * Data Structures:
 * Algorithms:
 * Other: Strings, Swap
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = int(s.size()) - 1;
        
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};

