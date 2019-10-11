/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com
 * Runtime: 8 ms - Beats 97.52% of submissions
 * Memory: 9.3 MB - Beats 86.79% of submissions
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current = head;
        ListNode *duplicate;
        while (current != NULL && current->next != NULL)
        {
            if (current->val == current->next->val)
            {
                duplicate = current->next;
                current->next = current->next->next;
                duplicate->next = NULL;
                delete duplicate;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }
};
