/*
LRU Cache (linked list + hashmap)

Problem: Implement LRU cache with get and put in O(1).
*/

// lru_cache.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  LRU Cache:
  - Doubly linked list + unordered_map.
  - Operations O(1).
*/

struct Node {
    int key,val;
    Node* prev; Node* next;
    Node(int k,int v):key(k),val(v),prev(nullptr),next(nullptr){}
};

class LRUCache{
    int cap;
    unordered_map<int,Node*> mp;
    Node* head,*tail;
public:
    LRUCache(int capacity):cap(capacity){
        head=new Node(0,0); tail=new Node(0,0);
        head->next=tail; tail->prev=head;
    }
    void remove(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void insert(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
    int get(int key){
        if(!mp.count(key)) return -1;
        Node* node=mp[key];
        remove(node); insert(node);
        return node->val;
    }
    void put(int key,int value){
        if(mp.count(key)){ remove(mp[key]); mp.erase(key);}
        if((int)mp.size()==cap){
            Node* lru=tail->prev;
            remove(lru); mp.erase(lru->key); delete lru;
        }
        Node* node=new Node(key,value);
        insert(node); mp[key]=node;
    }
};

int main(){
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cout<<cache.get(1)<<'\n'; //1
    cache.put(3,3); //evicts 2
    cout<<cache.get(2)<<'\n'; //-1
}
