/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 24 ms - Beats 69.89% of submissions
 * Memory: 13.7 MB - Beats 21.79% of submissions
 * Data Structures: (Unordered) Sets
 * Algorithms: 
 * Other:
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Unordered set to store (unique) numbers.
        unordered_set<int> set;
        // Iterate over array of numbers once.
        for (vector<int>::iterator it1 = nums.begin(); it1 != nums.end(); it1++)
        {
            // If number not in set, add it.
            if (set.find(*it1) == set.end())
            {
                set.insert(*it1);
            }
            // If number already in set, remove it.
            else 
            {
                set.erase(*it1);
            }
        }
        // The only remaining number left in the set
        // is the unique number.
        unordered_set<int>::iterator it2 = set.begin();
        return *it2;
    }
};
