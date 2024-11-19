#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//o(n) :: o(1)
int main(){
    vector<int> vec={6,3,-1,-3,4,-2,2,4,6,-12,-7};
    unordered_map<int,vector<int>> map;
    vector<pair<int,int>> out;
    int sum=0;
    for(int i=0;i<vec.size();i++){
        sum+=vec[i];
        if(sum==0){
            out.push_back(make_pair(0,i));
        }
        else{
            if(map.find(sum)!=map.end()){
                for(auto it=(map[sum]).begin();it!=(map[sum]).end();it++){
                    out.push_back(make_pair(*it+1,i));

                }
            }
        }
        map[sum].push_back(i);

    
    }
    for(int i=0;i<out.size();i++){
        cout << out[i].first << " " << out[i].second << endl;
    }
    return 0;
    


}