// C++ program to find the duplicate elements using Binary Search

#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& arr) {   
    sort(arr.begin(), arr.end());  
    vector<int> res;  

    int i = 0;
    while (i < arr.size()) { 
      
        // Index of first and last occurrence of arr[i]
        // using binary search
        int first = lower_bound(arr.begin(), arr.end(), arr[i]) - arr.begin();
        int last = upper_bound(arr.begin(), arr.end(), arr[i]) - arr.begin() - 1;
        
        // If the element occurs more than once, add it to res
        if (last > first) {  
            res.push_back(arr[i]);  
        }
      
        // Update i to the last index 
        // of the current element
        i = last + 1;
    }
    return res;
}

int main() {   
    vector<int> arr = {12, 11, 40, 12, 5, 6, 5, 12, 11};   
    vector<int> res = findDuplicates(arr); 
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";  
    return 0;
}
