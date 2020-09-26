/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 4 ms - Beats 87.67% of submissions
 * Memory: 8.1 MB - Beats 30.09% of submissions
 * Data Structures:
 * Algorithms: Recursion, Backtracking
 * Other: Permutations
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Resulting permutations.
        vector<vector<int>> permutations;
        // Current permutation set.
        vector<int> num_set;
        // Beginning of recursive (tree) calls.
        permuteBacktrack(permutations, num_set, nums);
        
        return permutations;
    }
    
    void permuteBacktrack(vector<vector<int>>& permutations, vector<int>& num_set, vector<int>& nums)
    {
        // Push permutation set to answers array 
        // if nums is empty, meaning there are no possible
        // numbers to choose from.
        if (nums.empty())
        {
            permutations.push_back(num_set);
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                // Create new numbers with current number removed.
                vector<int> new_nums = nums;
                new_nums.erase(new_nums.begin() + i);
                // Add removed number to current permutation set.
                num_set.push_back(nums[i]);
                // Recursive call, passing in new numbers,
                // with 1 number removed (added to number set).
                permuteBacktrack(permutations, num_set, new_nums);
                // Remove number from current permutation set
                // in the last position.
                // Ready to add next number and perform recursion.
                // Handled after returning from recursive call.
                num_set.pop_back();
            }
        }
    }
};
