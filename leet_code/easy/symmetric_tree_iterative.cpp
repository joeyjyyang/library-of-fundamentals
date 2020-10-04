/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 8 ms - Beats 61.51% of submissions
 * Memory: 17 MB - Beats 6.64% of submissions
 * Data Structures:
 * Algorithms:
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> queue;
        
        // Root points to nothing.
        if (root == nullptr)
        { 
            return true;
        }
        
        queue.push(root->left);
        queue.push(root->right);
        
        while (!queue.empty())
        {
            TreeNode* child1 = queue.front();
            queue.pop();
            TreeNode* child2 = queue.front();
            queue.pop();
            
            // Both children point to nothing,
            // Skip loop iteration; do not add children.
            if (child1 == nullptr && child2 == nullptr)
            {
                continue;
            }
            // Only one child points to nothing.
            else if (child1 == nullptr || child2 == nullptr)
            {
                return false;
            }
            // Children values are not equal.
            else if (child1->val != child2->val)
            {
                return false;
            }
            else
            {
                // Add mirror 1.
                queue.push(child1->left);
                queue.push(child2->right);
                // Add mirror 2.
                queue.push(child1->right);
                queue.push(child2->left);
            }
        }
        
        return true;
    }
};
