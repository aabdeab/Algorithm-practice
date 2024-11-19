#include <bits/stdc++.h>
using namespace std;
//o(V+E) :: o(V+E)

void DFSRecursive(vector<vector<int>> &v,vector<bool> &isVisited,int s){
    isVisited[s]=true;
    cout << s << " ";
    for(int i:v[s]){
        if(!isVisited[i]){
            DFSRecursive(v,isVisited,i);
        }
    }
    return ;

}
void  DFS(vector<vector<int>> &v,int s){
    vector<bool> isVisited(v.size(),false);
    DFSRecursive(v,isVisited,s);
}
void addEdge(vector<vector<int>> &v,int t,int s){
    v[s].push_back(t);
    v[t].push_back(s);
}
int main(){
    int V = 5; 
    vector<vector<int>> adj(V);
  
    // Add edges
    vector<vector<int>> edges={{1, 2},{1, 0},{2, 0},{2, 3},{2, 4}};
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    int s = 1; // Starting vertex for DFS
    cout << "DFS from source: " << s << endl;
    DFS(adj, s); // Perform DFS starting from the source vertex

    return 0;
}