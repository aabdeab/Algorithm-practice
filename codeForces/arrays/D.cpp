#include <bits/stdc++.h>
using namespace std;

int main(){
    
        int taille,nbr0;
        cin >> taille >> nbr0;
        if(taille ==0){
            cout << 0 << endl;
            return 0;
        }
        else if(taille ==1){
            cout << 0 << endl;
            return 0;
        }
        int arr[taille];
        int nbrPoints=0,levelIntel=0,levelStrength=0,nbrCheeks=0;
        for(int i=0; i <taille;i++){
            cin >> arr[i];
        }
        if(arr[0]!=0){
            cout << 0 << endl;
            return 0;
        }
        for(int i=0;i< taille;i++){
            if(arr[i]==0){
                nbrPoints++;
            }
            else if(arr[i]<0){
                if(abs(arr[i])>abs(levelStrength)){

                
                if(abs(arr[i])-abs(levelStrength)<=nbrPoints){
                    nbrPoints-=(abs(arr[i])-abs(levelStrength));
                    levelStrength = arr[i]; 
                    nbrCheeks++;
                }
                else{
                    cout << nbrCheeks << endl;
                    return 0;
                }
                }
                else{
                    nbrCheeks++;
                    
                };
            }
            else if(arr[i]>0){
                if(abs(arr[i])> abs(levelIntel)){
                if(abs(arr[i])-abs(levelIntel)<=nbrPoints){
                    nbrPoints-=(abs(arr[i])-abs(levelIntel));
                    levelIntel = arr[i]; 
                    nbrCheeks++;
                }
                else{
                    cout << nbrCheeks << endl;
                    return 0;
                }
                }
                else{
                    nbrCheeks++;
                    
                }
            }
            
        }
        cout << nbrCheeks << endl;

    
    return 0;
}