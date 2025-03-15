#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = NULL;
    }
};  // 🔹 **Added missing semicolon here**

class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue() {
        head = NULL;
    }

    // Insert an element based on priority
    void push(int n, int p) {
        Node* temp = new Node(n, p);

        // Case 1: If queue is empty or new node has highest priority
        if (head == nullptr || p <= head->priority) {
            temp->next = head;
            head = temp;
            return;
        }

        // Case 2: Insert at the correct position
        Node* cur = head;
        while (cur->next != nullptr && cur->next->priority <= p) {
            cur = cur->next;
        }

        temp->next = cur->next;
        cur->next = temp;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Remove and return the highest priority element
    int pop() {
        if (isEmpty()) return -1;

        Node* temp = head;   // 🔹 Store old head
        int value = head->data;
        head = head->next;   // 🔹 Move head to next node
        delete temp;         // 🔹 Free memory
        return value;
    }

    // Get the highest priority element without removing it
    int peek() {
        if (isEmpty()) return -1;
        return head->data;
    }
};

int main() {
    PriorityQueue pq;
    pq.push(30, 2);
    pq.push(50, 1);
    pq.push(20, 3);
    pq.push(40, 2);

    cout << "Popped element: " << pq.pop() << endl; // Expected: 50 (highest priority)

    return 0;  // 🔹 Added return statement for proper execution
}
