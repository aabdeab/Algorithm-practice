
#include <bits/stdc++.h>
using namespace std;

struct Pair{
    int min;
    int max;
};
//O(n) complexity and O(1) for storage
std::pair<int, int> findMax_Min(int arr[], int size) {
    if (size == 0) {
        return std::make_pair(0, 0);
    }

    int max = std::numeric_limits<int>::min();
    int min = std::numeric_limits<int>::max();

    for (int i = 0; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return std::make_pair(max, min);
}
//O(nlogn) complexity;O(1) for storage
std::pair <int,int> sorting_Methode(int arr[],int size){
    if(size == 0){
        return std::make_pair(0,0);
    }
    else{
        sort(arr,arr+size);
        return std::make_pair(arr[0],arr[size-1]);
    }
}
//O(n),storage:O(1)
Pair Methode(int arr[],int size){
    Pair minmax;
    if(size==1){
        minmax.min=arr[0];
        minmax.max=arr[0];
        return minmax;
    }
    if(arr[0]>arr[1]){
        minmax.min=arr[1];
        minmax.max=arr[0];
    }
    else{
        minmax.min=arr[0];
        minmax.max=arr[1];
    }
    for(int i=2;i<size;i++){
        if(arr[i]>minmax.max){
            minmax.max=arr[i];
        }
        if(arr[i]<minmax.min){
            minmax.min=arr[i];
        }

    }
    return minmax;


};
//O(n)(T(n)=2T(n/2)+const) ; O(log(n))
Pair Tournement_Methode(int arr[],int low,int high){
    Pair minmax,md,mr;
    if(low==high){
        minmax.min=arr[low];
        minmax.max=arr[low];
        return minmax;
    }
    if(high==low+1){
        if(arr[low]>arr[high]){
            minmax.min=arr[high];
            minmax.max=arr[low];
        }
        else{
            minmax.min=arr[low];
            minmax.max=arr[high];
        }
        return minmax;
    }
    int mid=(low+high)/2;
    mr=Tournement_Methode(arr,low,mid);
    md=Tournement_Methode(arr,mid+1,high);
    if(mr.min<md.min){
        minmax.min=mr.min;
    }
    else{
        minmax.min=md.min;
    }
    if(mr.max>md.max){
        minmax.max=mr.max;
    }
    else{
        minmax.max=md.max;
    }
    return minmax;
    
}


int main() {
    int arr[] = {3, 5, 1, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    //std::pair<int, int> result = findMax_Min(arr, size);
    //pair<int,int> result2=sorting_Methode(arr,size);
    //Pair result3=Methode(arr,size);
    Pair result4=Tournement_Methode(arr,0,size-1);
    std::cout << "Max: " << result4.max<< ", Min: " << result4.min << std::endl;

    return 0;
}


