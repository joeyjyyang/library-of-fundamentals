/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 24 ms - Beats 95.55% of submissions
 * Memory: 71.3 MB - Beats 9.56% of submissions
 * Data Structures: Linked Lists
 * Algorithms: 
 * Other: Modulo, Carry
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(carry); // 0
        ListNode* current = head;
        int sum = 0;
        while (l1 != nullptr || l2 != nullptr || carry)
        {
            sum = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
            // Always ones digit.
            current->next = new ListNode(sum % 10);
            current = current->next;
            // Get carry.
            carry = sum / 10;
            if (l1 != nullptr)
            {
                l1 = l1->next;
            }
            if (l2 != nullptr) 
            {
                l2 = l2->next;
            }
        }
        return head->next;
    }
};
