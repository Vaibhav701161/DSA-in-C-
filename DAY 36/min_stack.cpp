/*
 * DAY 36: Min Stack
 *
 * Problem Statement:
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 * Approach:
 * Use two stacks: one main stack and one auxiliary min stack.
 * The min stack always keeps track of the current minimum at each level.
 *
 * Time Complexity: O(1) for all operations
 * Space Complexity: O(n)
 */

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> mainStack;
    stack<int> minStack;
public:
    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top())
            minStack.push(val);
        else
            minStack.push(minStack.top());
    }

    void pop() {
        mainStack.pop();
        minStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << "Min: " << ms.getMin() << endl; // -3
    ms.pop();
    cout << "Top: " << ms.top() << endl;     // 0
    cout << "Min: " << ms.getMin() << endl;  // -2
    return 0;
}
