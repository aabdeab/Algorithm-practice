#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int subArraySum(int arr[],int n,int sum){
    unordered_map<int, int> prefixSum;
    int currSum = 0;
    int count =0;
    for(int i =0;i<n;i++){

        currSum += arr[i];
        if (currSum == sum) {
            count++;
            
        }
        if(prefixSum.find(currSum-sum)!= prefixSum.end()){
            count++;
        }
        prefixSum[currSum] =i;
    }
    return count;
}

int main()
{
    int arr[] = { 2, 4, -6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    // Function call
    int b=subArraySum(arr, n, sum);
    int size =sizeof(arr) / sizeof(arr[0]);
    cout <<(n*(n+1))/2 -b << endl;

    return 0;
}