/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com
 * Runtime: 4 ms - Beats 98.92% of submissions
 * Memory: 9.2 MB - Beats 83.21% of submissions
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
    ListNode* reverseList(ListNode* head) {
        ListNode *current{head};
        ListNode *trail{nullptr};
        while (current != nullptr)
        {
            current = head->next;
            head->next = trail;
            trail = head;
            head = current;
        }
        head = trail;
        return head;
    }
};
