#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;
/*
This is kosraju algo and thus algo is used to find the strongly connected graph and 
this is done in 3 steps
1. fnd the topo sort order
2. reverse the graph and then 
3, find the dfs with the order that was in the topo sort and then use the graph that has been reversed
*/
void dfstopo(unordered_map<int,list<int>> adj,int s,vector<bool>& vis,stack<int>& st){
    vis[s]=true;
    for(auto x:adj[s]){
        if(!vis[x]){
            dfstopo(adj,x,vis,st);
        }
    }
    st.push(s);
}
stack<int> topoSort(unordered_map<int,list<int>> adj,int v){
    vector<bool> visited(v,false);
    stack<int> st;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfstopo(adj,i,visited,st);
        }
    }
    return st;
}
unordered_map<int,list<int>> addEdgeReverse(vector<vector<int>>& a,int v,int e){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<v;i++){
        int u=a[i][0];
        int v=a[i][1];
        adj[v].push_back(u);
    }
    return adj;
}
unordered_map<int,list<int>> addEdge(vector<vector<int>>& a,int v,int e){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<v;i++){
        int u=a[i][0];
        int v=a[i][1];
        adj[u].push_back(v);
    }
    return adj;
}
void Dfsrec(unordered_map<int,list<int>>& adj,int s,vector<bool>& visited){
    visited[s]=true;
    for(auto x: adj[s]){
        if(!visited[x]){
            Dfsrec(adj,x,visited);
        }
    }
}
int Kosarju_Algo(vector<vector<int>>& a,int v,int e){
    int count=0;
    //setp 1- make the graph
    unordered_map<int,list<int>> adj=addEdge(a,v,e);

    //setp-2: make the topo sort
    stack<int> st=topoSort(adj,v);

    //setp3 ]: reverse the graph
    unordered_map<int,list<int>> adjReverse=addEdgeReverse(a,v,e);

    //step4: make the dfs travesal on the basis os stack st
    vector<bool> vis(v,false);
    while(!st.empty()){
        int top=st.top();
        st.pop();
        for(auto x:adj[top]){
            if(!vis[x]){
                count++;
                Dfsrec(adjReverse,x,vis);
            }
        }
    }
    return count;
}

int main(){
  int V=5,E=5;
    vector<vector<int>> edges = {
        {0,1},{1,2},{2,0},{1,3},{3,4}
    };

    cout<<"Number of Strongly Connected Components = "<<Kosarju_Algo(edges,V,E)<<endl;

    return 0;
}
