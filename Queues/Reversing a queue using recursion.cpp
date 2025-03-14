#include <bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q){
    if(q.empty()){
        return;
    }
    int front =q.front();
    q.pop();
    if(q.empty()){
        q.push(front);
        return;
    }
    reverse(q);
    q.push(front);
    return;
}
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // Print the original queue
    cout << "Original Queue: ";
    queue<int> temp = q; // Make a copy of the queue
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Reverse the queue
    reverse(q);

    // Print the reversed queue
    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}