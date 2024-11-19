#include <iostream>
#include <vector>
using namespace std;

//o(m+n) :: o(1)

int main(){
    vector<vector<int>> vec={
        {0, 0, 0},
        {0, 1, 1},
        {1, 1, 1}
    };
    int i=0;
    int j=vec[0].size()-1;
    while(i<vec.size() && j>=0){
        if(vec[i][j]==0){
            i++;
        }
        else{
            j--;
        }
    }
    cout << i<< endl;

    return 0;
};