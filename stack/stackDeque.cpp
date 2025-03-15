#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    deque<int> dq;

    // Default constructor
    Stack() {}

    // Constructor with initial value
    Stack(int n) {
        dq.push_front(n);
    }

    void push(int x) {
        dq.push_front(x);
    }

    int top() {
        if (!dq.empty()) {
            return dq.front();
        }
        throw runtime_error("Stack is empty");
    }

    void pop() {
        if (!dq.empty()) {
            dq.pop_front();
        } else {
            throw runtime_error("Stack is empty, cannot pop");
        }
    }

    bool isEmpty() {
        return dq.empty();
    }
};

int main() {
    Stack s;  // Now valid because of the default constructor
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl; // Output: 3
    s.pop();
    cout << s.top() << endl; // Output: 2
    return 0;
}
