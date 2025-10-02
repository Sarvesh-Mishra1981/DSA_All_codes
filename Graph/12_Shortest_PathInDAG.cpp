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
stack<int> Dfs(vector<int> adj[],int v){
    vector<bool> visited(v,false);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfsrec(adj,i,visited,s);
        }
    }
    return s;
}
void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt){
   adj[u].push_back({v, wt});
}
void getShortestDistance(vector<pair<int,int>> adj[],stack<int>& s,int src,vector<int>& dis){
    dis[src]=0;
    while(s.empty()==false){
        int top=s.top();
        s.pop();
        if(dis[top]!=INT_MAX){
           for(auto x:adj[top]){
            if(dis[top]+x.second<dis[x.first]){
                dis[x.first]=dis[top]+x.second;
            }
           }
        }
    }
}
int main(){
    int V = 6; 
    vector<pair<int,int>> adj[V];
    addEdge(adj, 0, 1, 5);
    addEdge(adj, 0, 2, 3);
    addEdge(adj, 1, 3, 6);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 2, 4, 4);
    addEdge(adj, 2, 5, 2);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 3, 4, -1);
    addEdge(adj, 4, 5, -2);
    vector<int> adjSimple[V];
    for(int u=0; u<V; u++){
        for(auto x: adj[u]){
            adjSimple[u].push_back(x.first);
        }
    }
    stack<int> s = Dfs(adjSimple, V);
    vector<int> dis(V, INT_MAX);
    int src = 1;
    getShortestDistance(adj, s, src, dis);
    cout << "Shortest distances from source " << src << ":\n";
    for(int i=0; i<V; i++){
        if(dis[i] == INT_MAX) cout << "INF ";
        else cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}