/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 36 ms - Beats 86.42% of submissions
 * Memory: 13.7 MB - Beats 52.78% of submissions
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        std::queue<TreeNode*> q1, q2;
        if (t1 == nullptr)
        {
            return t2;
        }
        else if (t2 == nullptr)
        {
            return t1;
        }
        else
        {
            q1.push(t1);
            q2.push(t2);    
            while (!q1.empty() && !q2.empty())
            {
                TreeNode* temp1 = q1.front();
                TreeNode* temp2 = q2.front();
                temp1->val += temp2->val;
                q1.pop();
                q2.pop();
                if (temp1->left == nullptr && temp2->left != nullptr)
                {
                    temp1->left = temp2->left;
                }
                else if (temp1->left != nullptr && temp2->left != nullptr)
                {
                    q1.push(temp1->left);
                    q2.push(temp2->left);
                }
                if (temp1->right == nullptr && temp2->right != nullptr)
                {
                    temp1->right = temp2->right;
                }
                else if (temp1->right != nullptr && temp2->right != nullptr)
                {
                    q1.push(temp1->right);
                    q2.push(temp2->right);
                }
            }
            return t1;
        }
    }
};

