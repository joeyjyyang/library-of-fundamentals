/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 4 ms - Beats 99.68% of submissions
 * Memory: 19.3 MB - Beats 8.27% of submissions
 * Data Structures: Binary Trees, Queues
 * Algorithms: BFS (Iteration)
 * Other: 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        if (root == nullptr)
        {
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        // Begin BFS traversal.
        while (!q.empty())
        {
            // Increment depth/level counter.
            max_depth++;
            // Get number of children nodes on current level.
            int n = q.size();
            // Traverse all children nodes of current level.
            for (int i = 0; i < n; i++)
            {
                TreeNode* child = q.front();
                q.pop();
                
                // Add children nodes of next level to queue.
                if (child->left != nullptr)
                {
                    q.push(child->left);
                }
                if (child->right != nullptr)
                {
                    q.push(child->right);
                }
            }
        }
            
        return max_depth;
    }
};
