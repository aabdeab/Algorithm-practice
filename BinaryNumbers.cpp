#include <bits/stdc++.h>
using namespace std;

void printBinaryNumbers(int n){
    for(int i=1;i<=n;i++){
        int temp=i;
        string str="";
        while(temp){
            str=((temp&1)==1)? "1" :"0"+ str;
            temp=temp>>1;
        }
        cout << str << endl;
    }
}


void generateBinaryNumbers(int n) {
    // Create an empty queue
    queue<string> q;

    // Enqueue the first binary number
    q.push("1");

    // Generate and print binary numbers
    for (int i = 1; i <= n; i++) {
        // Get the front of the queue
        string current = q.front();
        q.pop(); // Remove it from the queue

        // Print the current binary number
        cout << current << endl;

        // Append "0" to the current binary number and enqueue it
        q.push(current + "0");

        // Append "1" to the current binary number and enqueue it
        q.push(current + "1");
    }
}




int main(){
    int n=5;
    printBinaryNumbers(n);
    return 0;
 
}