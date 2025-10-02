#include<iostream>
#include<vector>
using namespace std;
bool Dfsrec(vector<int> adj[],int s,vector<bool>& recSt,vector<bool>& visited){
    visited[s]=true;
    recSt[s]=true;
    for(auto x: adj[s]){
        if(recSt[x]==true) return true;
        else if(visited[x]==false && Dfsrec(adj,x,recSt,visited)) return true;
    }
    recSt[s]=false;
    return false;
}
bool Dfs(vector<int> adj[],int v){
    vector<bool> visited(v,false);
    vector<bool> recSt(v,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(Dfsrec(adj,i,recSt,visited)==true) return true;
        }
    }
    return false;
}
void addEdge(vector<int> adj[],int v,int u){
    adj[v].push_back(u);
}
int main(){
int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);  
  
    cout<<Dfs(adj,V)<<endl;

	return 0; 
}
