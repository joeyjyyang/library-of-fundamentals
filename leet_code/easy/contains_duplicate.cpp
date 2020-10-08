/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 60 ms - Beats 87.80% of submissions
 * Memory: 20.4 MB - Beats 42.49% of submissions
 * Data Structures: Set
 * Algorithms:
 * Other: 
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            // Duplicate not found.
            if (set.find(*it) == set.end())
            {
                set.insert(*it);
            }
            // Duplicate found.
            else
            {
                return true;
            }
        }
        return false;
    }
};

