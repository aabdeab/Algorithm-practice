#include <bits/stdc++.h>
using namespace std;

int main(){
    string s="abc";
    vector<string> result;
    vector<bool> visited(s.size(),false);
    string current="";
    function<void()> permute=[&](){
        if(current.size()==s.size()){
            result.push_back(current);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(visited[i]){
                continue;
            }
            visited[i]=true;
            current.push_back(s[i]);
            permute();
            current.pop_back();
            visited[i]=false;
        }
    };
    permute();
    for(auto i:result){
        cout<<i<<endl;
    }
    return 0;
}