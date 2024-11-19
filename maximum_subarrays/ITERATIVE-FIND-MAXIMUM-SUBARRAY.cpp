#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>
using namespace std;

tuple<int ,int ,int> ITERATIVE_FIND_MAXIMUM_SUBARRAY(vector<int> &arr){
    int max_sum=INT_MIN;
    int sum = INT_MIN;
    int low;
    int high;
    for (int j = 0; j < arr.size(); j++) {
        high=j;
        if(sum>0){
            sum +=arr[j];
        }
        else {
            sum=arr[j];
            low=j;
        }
        if(sum>max_sum){
            max_sum=sum;
        }
    }
    return make_tuple(max_sum,low,high);

    }
    int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Find the maximum subarray using the recursive function
    auto result = ITERATIVE_FIND_MAXIMUM_SUBARRAY(arr);

    // Output the results
    cout << "max_sum " << get<0>(result) << endl;
    cout << "left index: " << get<1>(result) << endl;
    cout << "right index" << get<2>(result) << endl;

    return 0;
}

