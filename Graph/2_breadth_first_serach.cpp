#include<vector>
#include<iostream>
#include<queue>
using namespace std;
/* 
Here we are going to make the deapth first serach and it will be similar to that of the tree and push in the tree and 
then traverse the child and push them
*/
void BFS(vector<int> adj[],int v,int s){
    vector<int> visited(v+1,false);
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        cout<<top<<" ";
        for(int x:adj[top]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
            }
        }
    }
}
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    int v=5;
    vector<int> adj[v];
    addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);
    BFS(adj,v,0);  
}