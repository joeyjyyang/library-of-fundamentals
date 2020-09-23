/* 
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com
 * Runtime: 28 ms - Beats 66.08% of submissions
 * Memory: 11 MB - Beats 62.26% of submissions
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *current{head};
        ListNode *trail{nullptr};
        while(current != nullptr) 
        {
            if (current->val == val)
            {
                if (trail == nullptr)
                {
                    head = head->next;
                    delete current;
                    current = head;
                }
                else 
                {
                    current = current->next;
                    delete trail->next;
                    trail->next = current;
                }
            }
            else
            {
                trail = current;
                current = current->next;
            }
        }
        return head;
    }
};
