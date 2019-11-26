/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 8 ms - Beats 77.98% of submissions
 * Memory: 8.7 MB - Beats 100.00% of submissions
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* dummy = new ListNode(0);
        ListNode* current{dummy};
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1 != nullptr) current->next = l1;
        if (l2 != nullptr) current->next = l2;
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};
