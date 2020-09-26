/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 4 ms - Beats 87.71% of submissions
 * Memory: 7.8 MB - Beats 51.56% of submissions
 * Data Structures:
 * Algorithms: Recursion, Backtracking, DFS
 * Other: Permutations
 */

/*
     [1]      [2]      [3]
     / \      |  \      | \
  [1,2][1,3][2,1][2,3][3,1][3,2]
   /     \     \     \     \    \
[1,2,3][1,3,2][2,1,3][2,3,1][3,1,2][3,2,1]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Resulting permutations.
        vector<vector<int>> answer;
        // Current permutation set.
        vector<int> subset;
        // Beginning of recursive (tree) calls.
        permuteBacktrack(answer, subset, nums);

        return answer;
    }

    void permuteBacktrack(vector<vector<int>>& answer, vector<int>& subset, vector<int>& nums)
    {
        // Add permutation subset to answer if subset
        // is the same size as nums; a complete permutation.
        if (subset.size() == nums.size())
        {
            answer.push_back(subset);
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                // Number already exists in subset, so skip process below.
                if (find(subset.begin(), subset.end(), nums[i]) != subset.end())
                {
                    continue;
                }
                else
                {
                    // Add number to current permutation set.
                    subset.push_back(nums[i]);
                    // Recursive call, passing in new permutation set
                    // with number added.
                    permuteBacktrack(answer, subset, nums);
                    // Remove number from current permutation set
                    // in the last position.
                    // Ready to add next number and perform recursion.
                    // Handled after returning from recursive call.
                    subset.pop_back();
                }
            }
        }
    }
};
