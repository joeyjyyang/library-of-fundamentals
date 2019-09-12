/*
 * Runtime: 4 ms - Beats 98.48% of submissions
 * Memory: 9 MB - Beats 57.81% of submissions
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        vector<int>::iterator it;
        int index;

        for (it = nums.begin(); it != nums.end(); it++)
        {
            if (target <= *it)
            {
                index = it - nums.begin();
                return index;
            }
        }
        return nums.size();
    }
};
