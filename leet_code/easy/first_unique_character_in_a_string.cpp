/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 108 ms - Beats 50.07% of submissions
 * Memory: 11.1 MB - Beats 99.09% of submissions
 * Data Structures: Maps (Hash Tables)
 * Algorithms:
 * Other:
 */

class Solution {
public:
    int firstUniqChar(string s) {
        // Map to store character and index.
        // Index will be set to INT_MAX if duplicate character.
        unordered_map<char, int> map;
        
        // Traverse through string.
        for (int i = 0; i < s.size(); i++)
        {
            // If character unique,
            // add character and index to map.
            if (map.find(s[i]) == map.end())
            {
                // Add character and index.
                map[s[i]] = i;
            }
            // If character not unique (duplicate),
            // set index to INT_MAX.
            else 
            {
                map[s[i]] = INT_MAX;
            }
        }
        
        int min_index = INT_MAX;
        
        // Traverse through map/
        for (auto it : map)
        {
            int current_index = it.second;
            // Index (answer) is the minimum value (index) in the map.
            min_index = min(current_index, min_index);
        }
        
        // If all characters are duplicate,
        // index values are all INT_MAX.
        if (min_index == INT_MAX)
        {
            return -1;
        }
        else 
        {
            return min_index;
        }
    
    }
};
