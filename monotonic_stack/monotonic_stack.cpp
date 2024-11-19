#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> monotonic_increase(vector<int> &arr){
    stack<int> st;
    vector <int> result;
    for(int i=0; i<arr.size();i++){
        while(!st.empty() && st.top() > arr[i] ){
            st.pop();
        }
        st.push(arr[i]);
    }
    while(!st.empty()){
        result.insert(result.begin(),st.top());
        st.pop();
    }
    return result;
};
int main(){
    vector<int> arr ={1,2,3,4,5,9,8,222};
    auto result =monotonic_increase(arr);
    for(auto num :result){
        cout << num << endl;
    }
    return 0;
}
