/*
this is the sorting algo that is based on the thing that how my in degree is there in the particular node and hence
we sort it on the basis of the indegree;
*/
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
void Topological_Sorting(vector<int> adj[],int v){
    vector<int> indgree(v,0);
    queue<int> q;
    for(int i=0;i<v;i++){
        for(auto x:adj[i]){
            indgree[x]++;
        }
    }
    for(int i=0;i<v;i++){
        if(indgree[i]==0) {q.push(i);}
    }
    while(!q.empty()){
        int u=q.front();
        cout<<u<<" ";
        q.pop();
        for(auto x:adj[u]){
            if(--indgree[x]==0){
                q.push(x);
            }
        }
    }

}
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
}
int main(){
int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);  
  
    cout << "Following is a Topological Sort of\n"; 
    Topological_Sorting(adj,V);

	return 0; 
}
