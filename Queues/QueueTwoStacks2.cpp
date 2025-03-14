#include <bits/stdc++.h>
using namespace std;

struct Queue{
    stack<int> s1,s2;
    void enqueue(int value){
        s1.push(value);
    }
    int dequeue(){
        if(s1.empty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int value = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
};