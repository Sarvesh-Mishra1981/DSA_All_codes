/*
The basic idea is that in undirected and unweighted graph the min distance will be the parent dis+1 and we get the 
parent distance thorugh the bfs hence we just need to add one line in bfs traversal
*/
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
void BFS(vector<int> adj[],int s,vector<bool>& visited,vector<int>& distance){
    queue<int> q;
    q.push(s);
    distance[s]=0;
    visited[s]=true;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(int x:adj[top]){
            if(!visited[x]){
                distance[x]=distance[top]+1;
                q.push(x);
                visited[x]=true;
            }
        }
    }
}
void BFS_main(vector<int> adj[],int v,vector<int>& distance){
    vector<bool> visited(v+1,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            BFS(adj,i,visited,distance);
        }
    }
}
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printDis(vector<int>& dis,int v){
    for(int i=0;i<v;i++){
        cout<<dis[i]<<" ";
    }
}
int main(){
    int v=5;
    vector<int> adj[v];
    vector<int> distance(v+1,-1);
    addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);
    BFS_main(adj,v,distance);  
    printDis(distance,v);
}