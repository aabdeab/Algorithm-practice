#include <iostream>
#include <vector>
#include <limits>  // For std::numeric_limits

// Function to merge two halves using sentinel values
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of the left half
    int n2 = right - mid;     // Size of the right half

    // Create temporary vectors for the left and right subarrays
    std::vector<int> leftArr(n1 + 1), rightArr(n2 + 1);  // +1 for the sentinel value

    // Copy data to the temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Add sentinel values (+∞) at the end of the temporary arrays
    leftArr[n1] = std::numeric_limits<int>::max();  // Sentinel value for left half
    rightArr[n2] = std::numeric_limits<int>::max(); // Sentinel value for right half

    // Merge the two halves back into arr[]
    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
    }
}

// Function to implement merge sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves using the sentinel-optimized merge function
        merge(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();

    std::cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
        std::cout << arr[i] << " ";

    mergeSort(arr, 0, arr_size - 1);

    std::cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
        std::cout << arr[i] << " ";

    return 0;
}
