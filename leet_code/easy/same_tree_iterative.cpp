/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com
 * Runtime: 4 ms - Beats 55.76% of submissions
 * Memory: 10.4 MB - Beats 5.08% of submissions
 * Data Structures: Binary Trees
 * Algorithms: Iteration
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
        queue<TreeNode*> queue;
        
        //check tree structure
        if (p == NULL && q == NULL)
        {
            return true;
        }
        else if (p == NULL || q == NULL)
        {
            return false;
        }
        if (p != NULL && q != NULL)
        {
            queue.push(p);
            queue.push(q);
        }
        
        while (!queue.empty())
        {
            // Get both children nodes.
            TreeNode* child1 = queue.front(); 
            queue.pop();
            TreeNode* child2 = queue.front(); 
            queue.pop();
            // If children nodes both null, skip loop iteration.
            if (child1 == NULL && child2 == NULL) 
            {
                continue;
            }
            // Unequal children.
            if (child1 == NULL || child2 == NULL) 
            {
                return false;
            }
            // Unequal children.
            if (child1->val != child2->val) 
            {
                return false;
            }
            // Add both node's left children to queue.
            queue.push(child1->left);
            queue.push(child2->left);
            // Add both node's right children to queue.
            queue.push(child1->right);
            queue.push(child2->right);
        }
        
        return true;
    }
};
