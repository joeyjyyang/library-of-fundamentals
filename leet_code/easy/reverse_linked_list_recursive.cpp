/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com
 * Runtime: 8 ms - Beats 77.27% of submissions
 * Memory: 9.3 MB - Beats 68.70% of submissions
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
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *current = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return current;
    }
};
