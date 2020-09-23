/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 4 ms - Beats 98.17% of submissions
 * Memory: 19.4 MB - Beats 70.33% of submissions
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max_left = 0;
        int max_right = 0;
        if (root == nullptr)
        {
            return 0;
        }
        max_left = maxDepth(root->left) + 1;
        max_right = maxDepth(root->right) + 1;
        return max(max_left, max_right);
    }
};

