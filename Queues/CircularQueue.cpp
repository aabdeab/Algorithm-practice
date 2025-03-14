#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
    int *arr;
    int front, capacity, size;
    CircularQueue(int s) {
        front =-1;
        capacity=0;
        size = s;
        arr = new int[s];
    }

    void enQueue(int value){
        if(capacity==size){
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        else {
            int rear = (front+capacity)%size;
            arr[rear]=value;
            capacity++;
        }
    };
    int deQueue(){
        if(capacity==0){
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        else {
            int value = arr[front];
            front=(front+1)%size;
            capacity--;
            return value;
        }
    };
    void getFront(){
        if(capacity==0){
            cout << "Queue is empty." << endl;
            return;
        }
        else {
            cout << "Front element is " << arr[front] << endl;
        }
    }
    void getRear(){
        if(capacity==0){
            cout << "Queue is empty." << endl;
            return;
        }
        else {
            cout << "Rear element is " << arr[(front+capacity)%size] << endl;
        }
    }
    bool isEmpty(){
        return capacity==0;

    }
     ~CircularQueue() {
        delete[] arr;
    }
};