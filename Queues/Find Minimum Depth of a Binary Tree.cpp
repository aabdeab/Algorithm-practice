#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
struct qItem {
    Node* node;
    int depth;
};
int minDepth(Node *node){
   if(node ==NULL) return 0;
    queue<qItem> q;
    Node* temp=node;
    q.push({node,1});
    while(!q.empty()){
        int depth =q.front().depth;
        temp = q.front().node;
        q.pop();
        if(temp->right==NULL && temp ->left==NULL) return depth;
        if(temp->left!=NULL) q.push({temp->left,depth+1});
        if(temp->right!=NULL) q.push({temp->right,depth+1});
    }
}
int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(60);
    cout << minDepth(root);
    return 0;
}