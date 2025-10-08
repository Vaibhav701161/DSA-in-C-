#include <iostream>
using namespace std;

// Step 1: Define the structure of a Node
struct Node {
    int data;      // to store data
    Node* next;    // pointer to next node

    // Constructor to initialize a node easily
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Step 2: Function to convert array to linked list
Node* arrayToLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;  // if array empty, return null

    // Create head node using first element
    Node* head = new Node(arr[0]);
    Node* tail = head;  // tail always points to the last node

    // Loop through remaining elements
    for (int i = 1; i < size; i++) {
        Node* newNode = new Node(arr[i]); // create new node
        tail->next = newNode;             // link current tail to new node
        tail = newNode;                   // move tail to new node
    }

    return head;  // return starting node of linked list
}

// Step 3: Function to print linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " → ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Step 4: Main function
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = arrayToLinkedList(arr, size);

    cout << "Linked List: ";
    printLinkedList(head);

    return 0;
}
