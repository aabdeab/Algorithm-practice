#include <bits/stdc++.h>
using namespace std;

void printMaxWindows(vector<int> &vec,int k){
    deque<int> dq;
    int n=vec.size();
    for(int i=0;i<k;i++){
        while(!dq.empty() && vec[i]>=vec[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << vec[dq.front()] << endl;
    for(int i=k;i<n;i++){
        while(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        
        while(!dq.empty() && vec[i]>=vec[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        cout << vec[dq.front()] << endl;

    }

}
int main(){
    vector<int> vec = {12, 1, 78, 90, 56, 80, 100, 70};
    int k = 3;
    printMaxWindows(vec, k);
    return 0;
}