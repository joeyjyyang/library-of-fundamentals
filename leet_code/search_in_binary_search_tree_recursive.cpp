/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 52 ms - Beats 69.84% of submissions
 * Memory: 28.8 MB - Beats 100.00% of submissions
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
        {
            return root;
        }
        else
        {
            if (root->val == val)
            {
                return root;
            }
            else if (root->val > val)
            {
                root = searchBST(root->left, val);
            }
            else if (root->val < val)
            {
                root = searchBST(root->right, val);
            }
        }
        return root;
    }
};
