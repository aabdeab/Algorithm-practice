#include<bits/stdc++.h>
using namespace std;

struct stack{
    queue<int> q1,q2;
    void push(int val){
        q1.push(val);
    }
    int pop(){
        if(q1.empty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int temp = q1.front();
        q1.pop();
        swap(q1,q2);
        return temp;
    }
    int front(){
         if(q1.empty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int temp = q1.front();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return temp;

    }

};