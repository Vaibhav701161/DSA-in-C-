// 46_merge_k_sorted_lists.cpp
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    for (auto l: lists) if (l) pq.push(l);
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (!pq.empty()) {
        auto node = pq.top(); pq.pop();
        tail->next = node;
        tail = node;
        if (node->next) pq.push(node->next);
    }
    return dummy.next;
}

int main() {
    // build lists: (1->4->5), (1->3->4), (2->6)
    ListNode* l1 = new ListNode(1); l1->next = new ListNode(4); l1->next->next=new ListNode(5);
    ListNode* l2 = new ListNode(1); l2->next = new ListNode(3); l2->next->next=new ListNode(4);
    ListNode* l3 = new ListNode(2); l3->next = new ListNode(6);
    vector<ListNode*> lists = {l1,l2,l3};

    ListNode* merged = mergeKLists(lists);
    cout << "Merged list: ";
    while (merged) { cout << merged->val << " "; merged = merged->next; }
    cout << '\n';
    return 0;
}
