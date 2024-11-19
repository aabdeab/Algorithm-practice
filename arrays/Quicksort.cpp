#include <bits/stdc++.h>
using namespace std;
//o(n**2);

int partition(int *arr, int low, int high) {
    int pivot = arr[high];  // Pivot element is chosen as the last element
    int j = low - 1;        // Pointer for elements smaller than pivot
    
    for (int i = low; i < high; i++) {
        if (arr[i] <= pivot) {
            j++;            // Increment the smaller element pointer
            swap(arr[i], arr[j]);  // Swap the smaller element with the one at j
        }
    }
    swap(arr[j + 1], arr[high]);  // Place the pivot in the correct position
    return j + 1;  // Return the partition index
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // pi is the partition return index of pivot
        quickSort(arr, low, pi - 1);         // Recursively sort the left part
        quickSort(arr, pi + 1, high);        // Recursively sort the right part
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
  
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
