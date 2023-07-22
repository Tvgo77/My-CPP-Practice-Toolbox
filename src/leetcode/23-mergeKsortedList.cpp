#include "include/leetcode.h"

using namespace std;

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

/* Node comparision Class */
class NodeComparison {
public:
  bool reverse;

  NodeComparison(const bool& revparam=false) {reverse=revparam;}

  bool operator() (ListNode*& lhs, ListNode*& rhs) const {
    //if (reverse) return (lhs->val > rhs->val);

    //else 
    return (lhs->val > rhs->val);
  }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      /* Use Priority queue to solve this problem */
      ListNode* output = new ListNode();
      ListNode* head = output;

      /* Init priority queue */
      std::priority_queue<ListNode*, vector<ListNode*>, NodeComparison> nodePQ;

      /* Push every first node of k list to PQ */
      for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != nullptr)
          nodePQ.push(lists[i]);
      }

      // if (nodePQ.empty()) {
      //   return nullptr;
      // }

      /* Loop while PQ is not empty*/
      while (!nodePQ.empty()) {
        /* Pop the first(smallest) node in PQ */
        head->next = nodePQ.top();
        ListNode* curr = head->next;
        nodePQ.pop();

        /* If this node->next exist, push next node to PQ */
        if (curr->next != nullptr) {
          nodePQ.push(curr->next);
        }

        /* Update loop variable */
        head = head->next;
      }

      return output->next;
    }
};

int main() {
  ListNode* output;
  ListNode* head = output;

}