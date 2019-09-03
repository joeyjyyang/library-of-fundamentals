/*
 * Runtime: 8 ms - Beats 97.52% of submissions
 * Memory: 9.3 MB - Beats 86.79% of submissions
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
