#include <bits/stdc++.h>
using namespace std;

struct Queue{
    stack<int> s1,s2;
    void enqueue(int value){
        if(s1.empty()){
            s1.push(value);
            return;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(value);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int dequeue(){
        if(s1.empty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        int temp = s1.top();
        s1.pop();
        return temp;
    }
};