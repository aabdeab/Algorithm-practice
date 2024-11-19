#include <bits/stdc++.h>
using namespace std;

int main0(){
    //o(n) :: o(n);
    vector <int> v={1,1,4,5,1,1,2,2,1,1,8,1,1,3,1};
    int n=v.size();
    unordered_map<int,int> m;
    for(int c:v){
        m[c]++;
        if(m[c]>n/2){
            cout << c << endl;
            return n;
        }
    }
    cout << -1 << endl;
    return -1;
};
//moore's voting algorithm o(n) :: o(1):
int main(){
    vector<int> v={2,2,4,5,1,1,2,2,1,8,2,2,2,2,1,};
    int n=v.size();
    int majority=0,count=0;
    for(int i=0;i<n;i++){
        if(count==0){
            majority=v[i];
        }
        if(v[i]==majority){
            count++;
        }else{
            count--;
        }
    }
    count =0;
    for(auto c:v){
        if(c==majority){
            count++;
            if(count>n/2){
                cout << majority << endl;
                return majority;
            }
        }
    }
    cout << -1 << endl;
    return -1;


}