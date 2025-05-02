// reverse_k_group.cpp
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x=0): val(x), next(nullptr) {}
};

ListNode* reverseRange(ListNode* a, ListNode* b) {
    // reverse [a, b) and return new head
    ListNode* prev = nullptr;
    ListNode* cur = a;
    while (cur != b) {
        ListNode* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k <= 1) return head;
    ListNode* a = head;
    ListNode* b = head;
    for (int i = 0; i < k; ++i) {
        if (!b) return head; // not enough nodes
        b = b->next;
    }
    // reverse first k nodes
    ListNode* newHead = reverseRange(a, b);
    // a is now tail of reversed segment
    a->next = reverseKGroup(b, k);
    return newHead;
}

// helpers for testing
ListNode* build(const vector<int>& v) {
    ListNode* dummy = new ListNode();
    ListNode* t = dummy;
    for (int x : v) { t->next = new ListNode(x); t = t->next; }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}
void printList(ListNode* head) {
    while (head) { cout << head->val; if (head->next) cout << " -> "; head = head->next; }
    cout << '\n';
}
void freeList(ListNode* head) {
    while (head) { ListNode* t = head; head = head->next; delete t; }
}

int main() {
    vector<int> vals = {1,2,3,4,5,6,7};
    ListNode* head = build(vals);
    cout << "Original: "; printList(head);
    int k = 3;
    ListNode* res = reverseKGroup(head, k);
    cout << "After reverseKGroup k=" << k << ": "; printList(res);
    freeList(res);
    return 0;
}
