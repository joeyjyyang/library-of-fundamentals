/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 8 ms - Beats 61.51% of submissions
 * Memory: 16.6 MB - Beats 40.69% of submissions
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
	// Root points to nothing.
        if (root == nullptr)
        {
            return true;
        }
        else
        {
	    // Recursive tree.
            return isChildMirror(root->left, root->right);
        }
    }
    
    bool isChildMirror(TreeNode* child1, TreeNode* child2)
    {
	// Both children point to nothing.
        if (child1 == nullptr && child2 == nullptr)
        {
            return true;
        }
	// Only one child points to nothing
        else if (child1 == nullptr || child2 == nullptr)
        {
            return false;
        }
	else
        {
            return (child1->val == child2->val) && isChildMirror(child1->left, child2->right) && isChildMirror(child1->right, child2->left);
    }
};
