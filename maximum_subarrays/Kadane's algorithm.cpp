#include <iostream>
#include <vector>
using namespace std;


int maxsubArray(vector<int> &arr){
    int res =arr[0];
    int maxEnding = arr[0];
    for(int i=1;i<arr.size();i++){
        maxEnding = max(arr[i], maxEnding+arr[i]);
        res = max(res, maxEnding);
    }
    return res;

}