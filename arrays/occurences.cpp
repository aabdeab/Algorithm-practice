#include <iostream>
#include <vector>

using namespace std;

int findOccurences(int *arr,int n,int x){
    int res=0;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            res++;
        }
    }
    return res;
}
int findFirstOccurence(int *arr,int l,int h,int x){
    if(h>=l){
        int mid =(h+l)/2;
        if((mid==0 || arr[mid-1]<x)&& arr[mid]==x) return mid;
        else if(arr[mid]>x){
            return findFirstOccurence(arr,l,mid-1,x);
        }
        else{
            return findFirstOccurence(arr,mid+1,h,x);
        }
        
        };
        return -1;
};
int findLastOccurence(int *arr,int n,int l, int h, int x){
    if(h>=l){
        int mid=(h+l)/2;
        if((mid==n-1 || x<=arr[mid])&& arr[mid]==x) {
            return mid;
        }
        else if( x<arr[mid]){
            return findLastOccurence(arr,n/2,l,mid-1,x);
        }
        else{
            return findLastOccurence(arr,n/2,mid+1,h,x);
        }
    }
    return -1;
}
int countOccurrences(int arr[], int n, int x)
{

    // Find the first and last occurrences of the element
    int idxFirst = findFirstOccurence(arr, 0, n - 1, x);

    // If the element does not exist, return -1
    if (idxFirst == -1) {
        return -1;
    }
    int idxLast = findLastOccurence(arr, n, idxFirst, n - 1, x);

    // Return the difference between the last and first
    // occurrences + 1 to get the total count
    return idxLast - idxFirst + 1;
}

int main()
{
    int arr[] = { 1, 1, 2, 2, 2, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;

    int occurrences = countOccurrences(arr,n,  x);

    cout << "Number of occurrences of " << x << ": "
         << occurrences << std::endl;

    return 0;
}