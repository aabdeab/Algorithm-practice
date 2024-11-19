#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n ;
    cin >> n;
    while(n--){
        int size{0};
        cin >> size;
        vector<int>v(size);
        for(int i=0;i<size;i++){
            cin>> v[i];
            
        }
        if(size ==1){
            cout << v[0]*2 << endl;
        }
        if(size ==0){
            cout << 0<< endl;
        }
        else{
            int sum1=0,sum2=0;
            int Max1=v[0],Max2=v[1];
            for(int i=0;i<size;i+=2){
                sum1++;
                if(v[i]>Max1){
                    Max1=v[i];
                }
            }
            for(int j=1;j<size;j+=2){
                sum2++;
                if(v[j]>Max2){
                    Max2=v[j];
                }
            }
                
            cout << max(Max1+sum1,Max2+sum2) << endl;
        }
        
    }
    return 0;
}