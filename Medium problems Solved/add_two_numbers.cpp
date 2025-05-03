// add_two_numbers.cpp
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val; ListNode* next;
    ListNode(int x=0): val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy; ListNode* tail = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }
        carry = sum / 10;
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
    }
    return dummy.next;
}

// helpers
ListNode* build(const vector<int>& v) {
    ListNode dummy; ListNode* t = &dummy;
    for (int x : v) { t->next = new ListNode(x); t = t->next; }
    return dummy.next;
}
void printList(ListNode* h) {
    while (h) { cout<<h->val; if (h->next) cout<<"->"; h=h->next; } cout<<'\n';
}
void freeList(ListNode* h) { while (h) { ListNode* t=h; h=h->next; delete t; } }

int main() {
    ListNode* a = build({2,4,3}); // 342
    ListNode* b = build({5,6,4}); // 465
    cout << "A: "; printList(a);
    cout << "B: "; printList(b);
    ListNode* s = addTwoNumbers(a, b);
    cout << "Sum: "; printList(s); // 807 => 7->0->8
    freeList(a); freeList(b); freeList(s);
    return 0;
}
