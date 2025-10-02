/*
the thing that we used to do int the topo sort that is indegree concept and in this good but we can do directly it by the 
dfs search in the stack... as in that what we will do is that travers the graph and at the end we will insert 
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfsrec(vector<int> adj[],int s,vector<bool>& visited,stack<int>& st){
visited[s]=true;
    for(auto x:adj[s]){
        if(!visited[x]){
            dfsrec(adj,x,visited,st);
        }
    }
    st.push(s);
}
void Dfs(vector<int> adj[],int v){
    vector<bool> visited(v,false);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfsrec(adj,i,visited,s);
        }
    }
    while(s.empty()==false){
        cout<<s.top()<<" ";
        s.pop();
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
    Dfs(adj,V);

	return 0; 
}