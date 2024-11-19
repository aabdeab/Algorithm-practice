#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int n,k,q;
        cin >> n >> k >> q;
        vector<int> v1(n);
        vector<int> v2(k);
        for(int i=0;i<n ;i++){
            cin >> v1[i];
        }
        for(int i=0;i<k ;i++){
            cin >> v2[i];
        }
        int index1=0,index2=0;
        int isValid = 1;
        bool isGood = true;
        while(index1<n && index2<k){
            if(v1[index1]==v2[index2] && (isValid==1)){
                index2++;
                isValid =-1;
            }
            else if(v1[index1]==v2[index2] && (isValid==-1) ){
                index2++;
            }
            else if(v1[index1]!=v2[index2] && (isValid==1) ){
                isGood =false;
                cout << "TIDAK" << endl;
                break;
            }
            
            else {
                index1++;
                isValid=1;
               
            }  
            }
            if(isGood==true){
                cout << "YA" << endl;
            }
        }
        return 0;
    };


