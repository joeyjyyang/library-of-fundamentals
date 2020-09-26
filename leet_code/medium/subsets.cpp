/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 0 ms - Beats 100.0% of submissions
 * Memory: 7.3 MB - Beats 47.31% of submissions
 * Data Structures:
 * Algorithms: Recursion, Backtracking, DFS
 * Other: Subsets
 */


/*
         [     ]
        /   |  \
     [1]   [2]  [3]
     / \    \
  [1,2][1,3][2,3]
   /
 [1,2,3]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;
        // Resulting subsets.
        vector<vector<int>> answer;
        // Current subset (to be added to answer).
        vector<int> subset;
        // Beginning of recursive (tree) calls.
        subsetsBacktrack(answer, nums, subset, index);

        return answer;
    }

    void subsetsBacktrack(vector<vector<int>>& answer, vector<int>& nums, vector<int>& subset, int index)
    {
        // Add current subset to answer.
        // Initially add empty [] subset to answer.
        answer.push_back(subset);
        // Iterate through remaining numbers not in current subset.
        for (int i = index; i < nums.size(); i++)
        {
            // Add number to current subset.
            subset.push_back(nums[i]);
            // Recursive call, passing in new subset with current
            // number added, and also the incremented index.
            subsetsBacktrack(answer, nums, subset, i + 1);
            // Remove number from current subset
            // in the last position.
            // Ready to add next number and perform recursion.
            // Handled after returning from recursive call.
            subset.pop_back();
        }
    }
};


