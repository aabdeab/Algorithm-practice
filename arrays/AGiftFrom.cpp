#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    while(n--){
        int size;
        cin >> size;
        vector<int> vec(size);
        int i=0;
        int min=INT_MAX;
        int max=INT_MIN;
        while(i<size){
            cin >> vec[i];
            if(vec[i]>max){
                max=vec[i];
            }
            if(vec[i]<min){
                min=vec[i];
            }
            i++;
        };
        cout << (max-min)*(size-1) << endl;
        
        
    }
    return 0;
    
    
}