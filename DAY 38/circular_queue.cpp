/*
 * DAY 38: Design Circular Queue
 *
 * Problem Statement:
 * Design a circular queue (ring buffer) that supports enQueue, deQueue,
 * Front, Rear, isEmpty, and isFull operations.
 *
 * Approach:
 * Use a fixed-size array with front and rear pointers.
 * Use modular arithmetic to wrap around the array ends.
 *
 * Time Complexity: O(1) for all operations
 * Space Complexity: O(k) where k is the size of the queue
 */

#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
    vector<int> data;
    int front, rear, size, capacity;
public:
    MyCircularQueue(int k) : data(k), front(0), rear(-1), size(0), capacity(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front() { return isEmpty() ? -1 : data[front]; }
    int Rear()  { return isEmpty() ? -1 : data[rear]; }
    bool isEmpty() { return size == 0; }
    bool isFull()  { return size == capacity; }
};

int main() {
    MyCircularQueue cq(3);
    cout << cq.enQueue(1) << endl; // 1
    cout << cq.enQueue(2) << endl; // 1
    cout << cq.enQueue(3) << endl; // 1
    cout << cq.enQueue(4) << endl; // 0 (full)
    cout << "Rear: " << cq.Rear() << endl; // 3
    cout << cq.deQueue() << endl;          // 1
    cout << cq.enQueue(4) << endl;         // 1
    cout << "Rear: " << cq.Rear() << endl; // 4
    return 0;
}
