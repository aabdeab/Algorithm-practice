#include <bits/stdc++.h>

using namespace std;
int main(){
    map<string,int> map;
    map["apple"]=1;
    map["banana"]=2;
    map["blackberry"]=3;
    map["orange"]=4;
    map.insert(pair<string,int>("hello",5));
    map.insert(make_pair("world",6));
    auto it=map.begin();
    it = map.lower_bound("b");
    cout << "The lower bound of key 3 is ";
    cout << (*it).first << " " << (*it).second;
    while(it!=map.end()){
        cout<<(*it).first<<" "<<it->second<<endl;
        it++;
    }
    
}