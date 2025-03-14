#include <bits/stdc++.h>
using namespace std;
//First method
queue<int> reverseFirstK(queue<int> &q , int k){
    if(k<=0 || k>q.size()){
        return q;
    }
    stack<int> s;
    while(k--){
        s.push(q.front());
        q.pop();
    }
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        s.push(temp);
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
}
// Seconf method 
void solve(queue<int> &q ,int k);
queue<int> reversefirstK(queue<int> &q , int k){
    if(k<=0 || k>q.size()){
        return q;
    }
    solve(q,k);
    int x= q.size()-k;
    while(x-->0){
        int temp = q.front();
        q.pop();
        q.push(temp);
    };
    return q;
}
void solve(queue<int> &q , int k){
    if(k==0){
        return;
    }
    int temp = q.front();
    q.pop();
    solve(q,k-1);
    q.push(temp);
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k = 3;
    q = reversefirstK(q, k);
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}