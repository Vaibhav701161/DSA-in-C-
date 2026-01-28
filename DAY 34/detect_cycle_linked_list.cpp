/*
 * DAY 34: Detect Cycle in a Linked List
 *
 * Problem Statement:
 * Given the head of a linked list, determine if the linked list has a cycle.
 * Return true if there is a cycle, otherwise false.
 *
 * Approach:
 * Floyd's Cycle Detection Algorithm (Two Pointers - Slow and Fast).
 * Slow pointer moves one step, fast pointer moves two steps. If they meet,
 * there is a cycle.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    // Create list: 3 -> 2 -> 0 -> -4 (cycle back to node 2)
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // cycle

    cout << "Has cycle: " << (hasCycle(head) ? "true" : "false") << endl;
    return 0;
}
