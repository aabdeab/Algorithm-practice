#include <bits/stdc++.h>
using namespace std;

//o(nlogn) :: o(n)
int main0(int argc,char** argv){
    vector<int> vec={10,5,6,3,2,20,100,80};
    sort(vec.begin(),vec.end());
    for(int i=0;i+1<vec.size();i+=2){
        swap(vec[i],vec[i+1]);
    }
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    return 0;
 
}

//o(n) :: o(1)
int main(){
    vector<int> vec={10,5,6,3,2,20,100,80};
    for(int i=0;i<vec.size();i+=2){
        if(i>0 && vec[i-1]>vec[i]){
            swap(vec[i],vec[i-1]);
            
        }
        if(i<vec.size()-1 && vec[i+1]> vec[i]){
            swap(vec[i],vec[i+1]);
        }
    }
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    return 0;


}