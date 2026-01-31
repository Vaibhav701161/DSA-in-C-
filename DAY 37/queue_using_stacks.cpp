/*
 * DAY 37: Implement Queue Using Two Stacks
 *
 * Problem Statement:
 * Implement a first-in-first-out (FIFO) queue using only two stacks.
 * Implement push, pop, peek, and empty operations.
 *
 * Approach:
 * Use two stacks: input stack and output stack.
 * Push: always push to input stack.
 * Pop/Peek: if output stack is empty, move all elements from input to output.
 *
 * Time Complexity: Amortized O(1) per operation
 * Space Complexity: O(n)
 */

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> inputStack;
    stack<int> outputStack;

    void transfer() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }
public:
    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (outputStack.empty()) transfer();
        int val = outputStack.top();
        outputStack.pop();
        return val;
    }

    int peek() {
        if (outputStack.empty()) transfer();
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1); q.push(2); q.push(3);
    cout << "Peek: " << q.peek() << endl; // 1
    cout << "Pop: " << q.pop() << endl;   // 1
    cout << "Pop: " << q.pop() << endl;   // 2
    cout << "Empty: " << q.empty() << endl; // 0
    return 0;
}
