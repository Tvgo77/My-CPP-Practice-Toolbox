#include "include/leetcode.h"

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
    ListNode* swapPairs(ListNode* head) {
        /* Recursively solve this problem */

        /* Edge case: node num == 0 */
        if (head == nullptr) {
            return {};
        }

        /* Get 2 nodes from head*/
        /* Return case 1: only one node */
        ListNode* second = head->next;
        if (!second) {
            return head;  // No need for swap
        }

        /* Return case 2: only 2 node */
        if (!second->next) {
            second->next = head;
            head->next = nullptr;  // Swap 2 nodes;
            return second;
        }

        /* Recursive function: swap and link second node (original head node) to
           return value(swapped node) of recursive function */
        ListNode* newHead = second->next;
        second->next = head;
        head->next = swapPairs(newHead);

        return second;
    }
};