#include<iostream>
#include<vector>
using namespace std;
/*
The important thing to note is that if we crete the adjency matrix then the space complexity will be VxV and but when we 
create the adjency list then the space complexity will be O(v+e) for the directed graph and the O(v+2e) for the 
undirected graph.
*/
void addEdge(vector<int> adj[],int v,int u){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAdjaency(vector<int> adj[],int v){
    for(int i=0;i<v;i++){
        for(int x:adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int v=5;
    vector<int> adj[v];
    addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);  
    printAdjaency(adj,v);
    return 0;
}
