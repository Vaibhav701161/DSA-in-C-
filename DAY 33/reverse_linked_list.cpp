/*
 * DAY 33: Reverse a Linked List
 *
 * Problem Statement:
 * Given the head of a singly linked list, reverse the list and return the
 * reversed list's head.
 *
 * Approach:
 * Iterative approach using three pointers: prev, curr, next.
 * At each step, reverse the current node's next pointer to point to prev.
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

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original: ";
    printList(head);
    head = reverseList(head);
    cout << "Reversed: ";
    printList(head);
    return 0;
}
