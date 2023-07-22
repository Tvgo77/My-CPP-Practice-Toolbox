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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tail = new ListNode(0, nullptr);
        ListNode* output = tail;

        /* Loop, terminate when no uncompared element is left in list1 or list2*/
        while (list1 != nullptr && list2 != nullptr) {
            /* Get smallest element of list1 and list2 */
            ListNode* smallerNode = (list1->val < list2->val)? list1: list2;
            
            /* Set address of tail-next to this element */
            tail->next = smallerNode;

            /* Update pointer*/
            if (smallerNode == list1) {
                list1 = list1->next;
            }
            else if (smallerNode == list2) {
                list2 = list2->next;
            }

            tail = tail->next;
        }

        while (list1 != nullptr) {
            tail->next = list1;
            list1 = list1->next;
            tail = tail->next;
        }

        while (list2 != nullptr) {
            tail->next = list2;
            list2 = list2->next;
            tail = tail->next;
        }

        return output->next;
    }
};

int main() {
    Solution solution;
    ListNode* input1 = new ListNode(1);
    ListNode* input2 = new ListNode(2);
    ListNode* expect = new ListNode(1);

    input1->append(3);
    input1->append(5);
    input2->append(4);
    input2->append(6);

    expect->append(1);
    expect->append(2);
    expect->append(3);
    expect->append(4);
    expect->append(5);
    expect->append(6);

    testTool(&Solution::mergeTwoLists, expect, input1, input2);
    return 0;
}