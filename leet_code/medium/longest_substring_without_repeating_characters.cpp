/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 60 ms - Beats 33.52% of submissions
 * Memory: 11.2 MB - Beats 22.50% of submissions
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        
        // Set size will be the length of the longest substring 
        // without repeating characters.
        unordered_set<char> set;
        
        // Tracks left boundary of sliding window.
        string::iterator it1 = s.begin();
        
        // Tracks right boundary of sliding window.
        string::iterator it2 = it1;
       
	// Can also use for loop, but slower than while loop.
        while (it1 != s.end() && it2 != s.end())
        {
            // Unique character; does not exist in set.
            if (set.find(*it2) == set.end())
            {
                set.insert(*it2);
                length = max(length, int(set.size()));
		// Extend right boundary.
                it2++;
            }
            // Duplicate character; already exists in set.
            else 
            {
                set.erase(*it1);
		// Extend left boundary.
                it1++;
            }
        }
        return length;
    }
};
