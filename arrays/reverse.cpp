#include <bits/stdc++.h>
using namespace std;

//o(n)::o(1)
void reverse(int *arr,int n){
    ;
    for(int i=0;i<n/2;i++){
        swap(arr[i],arr[n-i-1]);
    }
    return;
}
//o(n) :: o(n)
void reverse_Recusion(int *arr,int low,int high,int size){
    if(size<=1)return;
    if(size==2){
        swap(arr[low],arr[high]);
        return;
    };
    if(size>=3){
        swap(arr[low],arr[high]);
        reverse_Recusion(arr,low+1,high-1,size-2);
        return;
    }
    
}

//o(n) :: o(1) STL reverse uses swapping
void ReverseArray(vector<int>&arr){
    reverse(arr.begin(),arr.end());
    return;
}
void reverseArray(vector<int> &arr) {
  
    // Initialize left to the beginning and right to the end
    int left = 0, right = arr.size() - 1;
  
    // Iterate till left is less than right
    while(left < right) {
      
        // Swap the elements at left and right position
        swap(arr[left], arr[right]);
      
        // Increment the left pointer
        left++;
      
        // Decrement the right pointer
        right--;
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    vector<int> vec={1,2,3,4,5};
    int n= sizeof(arr)/sizeof(arr[0]);
    ReverseArray(vec);
    for(int i=0;i<5;i++){
        cout << vec[i] << " ";
    }
    return 0;
 
}