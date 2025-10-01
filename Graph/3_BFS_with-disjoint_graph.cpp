#include<vector>
#include<iostream>
#include<queue>
using namespace std;
/* 
the idea here is that somethimes the graph maybe disconnected so what we d is we run another loop to check wether the node is 
traversed or not 
The time cmplexity here is O(v+e) coz you run the loop v times to check the disjoint and u run the loop for the edges.
*/
void BFS(vector<int> adj[],int s,vector<bool>& visited){
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
void BFS_main(vector<int> adj[],int v){
    vector<bool> visited(v+1,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            BFS(adj,i,visited);
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
    BFS_main(adj,v);  
}