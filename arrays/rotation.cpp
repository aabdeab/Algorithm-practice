#include <bits/stdc++.h>
using namespace std;

// for all o(n) :: o(1)
void rotation(int *arr,int size,int nbr){
    while(nbr--){
        if(size<=1){
            return;
        }
        else{
            int temp =arr[size-1];
            for(int i=size-1;i>0;i--){
                arr[i]=arr[i-1];
            }
            arr[0]=temp;
        }
    }
    return;
};

void rotation(int *arr,int size){
    int i=0,j=size-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
    }
    return;
}

void rotation(vector <int>&arr){
    if(arr.size()<=1){
        return;
    }
    reverse(arr.begin(),arr.end());
    reverse(arr.begin()+1,arr.end());
    return;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    vector<int>vec={1,2,3,4,5,6,7,8,9};
    rotation(vec);
    for(int i=0;i<9;i++){
        cout << vec[i] << " ";
    }
}
