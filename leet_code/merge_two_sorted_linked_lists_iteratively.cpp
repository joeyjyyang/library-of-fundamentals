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
        ListNode* head;
        if (l1->val <= l2->val) head = l1;
        else
        {
            head = l2;
            l2 = l1;
            l1 = head;  
        }
        ListNode* temp;
        while (l1->next != nullptr && l2 != nullptr)
        {
            if (l1->next->val <= l2->val) l1 = l1->next;
            else
            {
                temp = l1->next;
                l1->next = l2;
                l2 = temp;
            }
        }
        l1->next = l2;
        return head;
    }
};

