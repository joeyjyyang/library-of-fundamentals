/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com
 * Runtime: 4 ms - Beats 58.85% of submissions
 * Memory: 9.7 MB - Beats 100.00% of submissions
 * Data Structures: Binary Trees
 * Algorithms: Recursion
 * Other: Pointers
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //check tree structure
        if (p == NULL && q == NULL)
        {
            return true;
        }
        else if (p == NULL || q == NULL)
        {
            return false;
        }
        //check node value
        if (p->val != q-> val)
        {
            return false;
        }
        else
        {
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }
    }
};

