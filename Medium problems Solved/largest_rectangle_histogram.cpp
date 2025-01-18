// 42_largest_rectangle_histogram.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Use stack to keep increasing heights.
  When a bar is smaller, pop and calculate max area using popped bar as height.
  Time: O(n)
*/

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;
    for (int i = 0; i <= n; ++i) {
        int h = (i == n ? 0 : heights[i]);
        while (!st.empty() && h < heights[st.top()]) {
            int height = heights[st.top()]; st.pop();
            int left = st.empty() ? 0 : st.top() + 1;
            int width = i - left;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Largest rectangle area: " << largestRectangleArea(heights) << '\n';
    return 0;
}
    freqList[1]->addNode(newNode);
            minFreq = 1;
        } else {
            freqList[1]->addNode(newNode);
        }
        curSize++;
    } else {
        Node* node = keyNode[key];
        node->value = value;
        updateFreq(node);
    }
}   
    if (keyNode.find(key) != keyNode.end()) {
        Node* node = keyNode[key];
        node->value = value;
        updateFreq(node);
        return node->value;
    } else {
        if (curSize == capacity) {
            DLList* list = freqList[minFreq];
            Node* nodeToRemove = list->removeLastNode();
            keyNode.erase(nodeToRemove->key);
            delete nodeToRemove;
            curSize--;
        }
        Node* newNode = new Node(key, value);
        keyNode[key] = newNode;
        if (freqList.find(1) == freqList.end()) {
            freqList[1] = new DLList();
        }
        freqList[1]->addNode(newNode);
        minFreq = 1;
        curSize++;
        return value;
    }
}
    if (keyNode.find(key) != keyNode.end()) {
        Node* node = keyNode[key];
        node->value = value;
        updateFreq(node);
        return node->value;
    } else {
        if (curSize == capacity) {
            DLList* list = freqList[minFreq];
            Node* nodeToRemove = list->removeLastNode();
            keyNode.erase(nodeToRemove->key);
            delete nodeToRemove;
            curSize--;
        }
        Node* newNode = new Node(key, value);
        keyNode[key] = newNode;
        if (freqList.find(1) == freqList.end()) {
            freqList[1] = new DLList();
        }
        freqList[1]->addNode(newNode);
        minFreq = 1;
        curSize++;
        return value;
    }
}       
