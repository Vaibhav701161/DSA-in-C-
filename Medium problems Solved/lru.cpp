#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, value, freq;
    Node *prev, *next;
    Node(int k, int v) : key(k), value(v), freq(1), prev(NULL), next(NULL) {}
};

struct DLList {
    Node *head, *tail;
    int size;
    DLList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addNode(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }
    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
    Node* removeLastNode() {
        if(size == 0) return NULL;
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
};

class LFUCache {
    int capacity, minFreq, curSize;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, DLList*> freqList;

public:
    LFUCache(int cap) {
        capacity = cap;
        minFreq = 0;
        curSize = 0;
    }

    int get(int key) {
        if(keyNode.find(key) == keyNode.end()) return -1;
        Node* node = keyNode[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if(capacity == 0) return;
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreq(node);
        } else {
            if(curSize == capacity) {
                DLList* list = freqList[minFreq];
                Node* toRemove = list->removeLastNode();
                keyNode.erase(toRemove->key);
                curSize--;
            }
            Node* newNode = new Node(key, value);
            minFreq = 1;
            if(freqList.find(1) == freqList.end()) freqList[1] = new DLList();
            freqList[1]->addNode(newNode);
            keyNode[key] = newNode;
            curSize++;
        }
    }

private:
    void updateFreq(Node* node) {
        int freq = node->freq;
        freqList[freq]->removeNode(node);
        if(freq == minFreq && freqList[freq]->size == 0) minFreq++;
        node->freq++;
        if(freqList.find(node->freq) == freqList.end())
            freqList[node->freq] = new DLList();
        freqList[node->freq]->addNode(node);
    }
};

int main() {
    LFUCache lfu(2);
    lfu.put(1, 10);
    lfu.put(2, 20);
    cout << lfu.get(1) << endl; // Output: 10
    lfu.put(3, 30);
    cout << lfu.get(2) << endl; // Output: -1 (evicted)
    cout << lfu.get(3) << endl; // Output: 30
}
