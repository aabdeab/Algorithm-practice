#include <iostream>
#include <vector>
using namespace std;

int solution(vector <int> &arr){
    int profit=0;
    if(arr.size()<=1){
        return 0;
    }
    for (int i=1;i<arr.size();i++){
        if(arr[i]> arr[i-1] > 0){
            profit+=arr[i]-arr[i-1];
        }
    }
    return profit;

}
int Solution2(vector <int> &arr){
    int min=0,max=0;
    int profit=0;
    if(arr.size()<=1){
        return 0;
    }
    if(arr[0]< arr[1]){
        min=arr[0];
    }
    for(int i=1;i<arr.size()-1;i++){
        if(arr[i]>=arr[i-1] && arr[i+1]<arr[i]){
            max=arr[i];
            profit+=max-min;
        }
        else if(arr[i]<=arr[i-1] && arr[i+1]>arr[i]){
            min=arr[i];
        }
        else{
            continue;
        }
    }
    if(arr[arr.size()-1]>=arr[arr.size()-2]){
        max=arr[arr.size()-1];
        profit+=max-min;
    }
    return profit;
    
}

int main(int argc,char **argv){
    vector <int> arr={5,9,2000,2,10,8888,3,4,10000,2000};
    cout << "Maximum profit: " << Solution2(arr) << endl;
    return 0;
    

}