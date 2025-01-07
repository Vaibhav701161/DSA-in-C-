/*
Clone Graph (DFS + hashmap)

Problem: Given reference to a node in a connected undirected graph, return deep copy.
*/

// clone_graph.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Clone graph using DFS with hashmap for visited nodes.
*/

struct Node {
    int val;
    vector<Node*> neighbors;
    Node(int _val):val(_val){}
};

unordered_map<Node*,Node*> mp;

Node* clone(Node* node){
    if(!node) return nullptr;
    if(mp.count(node)) return mp[node];
    Node* copy=new Node(node->val);
    mp[node]=copy;
    for(auto nei:node->neighbors){
        copy->neighbors.push_back(clone(nei));
    }
    return copy;
}

int main(){
    Node* a=new Node(1); Node* b=new Node(2);
    Node* c=new Node(3); Node* d=new Node(4);
    a->neighbors={b,d}; b->neighbors={a,c};
    c->neighbors={b,d}; d->neighbors={a,c};
    Node* copy=clone(a);
    cout<<"Cloned node value: "<<copy->val<<'\n';
}
