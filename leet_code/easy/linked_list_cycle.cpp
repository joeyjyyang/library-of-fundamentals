/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 8 ms - Beats 91.90% of submissions
 * Memory: 7.9 MB - Beats 13.52% of submissions
 * Data Structures: Linked Lists
 * Algorithms:
 * Other: Two Pointers
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
    bool hasCycle(ListNode *head) {
        // Traverses by 2.
        ListNode* fast_pointer = head;
        // Traverses by 1.
        ListNode* slow_pointer = head;
        
        // Iterate around linked list until fast pointer
        // meets slow pointer (cycle).
        while (fast_pointer != nullptr && fast_pointer->next != nullptr)
        {
            fast_pointer = fast_pointer->next->next;
            slow_pointer = slow_pointer->next;
            // Fast pointer goes around cyclic
            // linked list, and meets slow pointer.
            if (fast_pointer == slow_pointer)
            {
                return true;
            }
        }
        
        // Fast pointer reaches end of acyclic linked list,
        // and never meets slow pointer.
        return false;
    }
};
