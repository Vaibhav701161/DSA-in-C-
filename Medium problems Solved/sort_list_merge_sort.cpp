// sort_list_merge_sort.cpp
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val; ListNode* next;
    ListNode(int x=0): val(x), next(nullptr) {}
};

ListNode* mergeTwo(ListNode* a, ListNode* b) {
    ListNode dummy; ListNode* t = &dummy;
    while (a && b) {
        if (a->val < b->val) { t->next = a; a = a->next; }
        else { t->next = b; b = b->next; }
        t = t->next;
    }
    t->next = (a ? a : b);
    return dummy.next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    // find mid
    ListNode* slow = head; ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    return mergeTwo(left, right);
}

// helpers
ListNode* build(const vector<int>& v) {
    ListNode dummy; ListNode* t = &dummy;
    for (int x : v) { t->next = new ListNode(x); t = t->next; }
    return dummy.next;
}
void printList(ListNode* h) { while (h) { cout<<h->val; if (h->next) cout<<" -> "; h=h->next; } cout<<'\n'; }
void freeList(ListNode* h) { while (h) { ListNode* t=h; h=h->next; delete t; } }

int main() {
    auto head = build({4,2,1,3,7,5});
    cout << "Before sort: "; printList(head);
    head = sortList(head);
    cout << "After sort:  "; printList(head);
    freeList(head);
    return 0;
}
