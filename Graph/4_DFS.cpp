#include<iostream>
#include<vector>
using namespace std;
void DFS(vector<int> adj[],int s,vector<bool> & visited){
    visited[s]=true;
    cout<<s<<" ";
    for(auto x:adj[s]){
        if(!visited[x]){
            DFS(adj,x,visited);
        }
    }

}
void DFS_main(vector<int> adj[],int v){
    vector<bool> visited(v+1,false);
            DFS(adj,0,visited);
}
void addEdge(vector<int> adj[],int v,int u){
    adj[v].push_back(u);
    adj[u].push_back(v);
}
int main(){
    int v=5;
    vector<int> adj[v];
    addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);
    DFS_main(adj,v);  
}