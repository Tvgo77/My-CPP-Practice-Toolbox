#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <functional>
#include <stdio.h>
#include <cstdint>

class Solution;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    /* Self-implement tool function */
    void append(int x) {
        ListNode* newNode = new ListNode(x);
        ListNode* nextNode = this;
        while (nextNode->next != nullptr) {
            nextNode = nextNode->next;    
        }
        nextNode->next = newNode;
    }
};

template <typename Func, typename Expect, typename... Args>
auto testTool(Func&& func, Expect&& expect, Args&&... args) {
    Solution solution;
    auto testFunc = std::bind(std::forward<Func>(func), &solution, std::forward<Args>(args)...);
    auto output = testFunc();
    bool b = (expect == output);
    return b;
}