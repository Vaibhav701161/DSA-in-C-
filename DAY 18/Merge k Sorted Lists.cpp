class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
            priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
            for (auto l : lists) {
                if (l) pq.push(l);
            }
            ListNode dummy(0), *tail = &dummy;
            while (!pq.empty()) {
                ListNode* node = pq.top(); pq.pop();
                tail->next = node;
                tail = tail->next;
                if (node->next) pq.push(node->next);
            }
            return dummy.next;
        }
    };
    