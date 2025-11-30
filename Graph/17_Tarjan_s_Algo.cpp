/*
so as mentioned earlier we have idea so just implementing that idea


THIS QUESTION IS SIMILAR TO FIND THE BRIDGE IN THE GRAPH
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
void Tarjan(unordered_map<int,list<int>>& adj,vector<int>& disc,vector<int>& low,
            int parent,unordered_map<int,bool>& vis,vector<vector<int>>& res,int node,int& timer){
            
                vis[node]=true;
                low[node]=disc[node]=timer++;
                for(auto x:adj[node]){
                    //if it is parents then just continue
                    if(x==parent) continue;
                    
                    // the next conditon is that if it is no visited then 
                    //what we will do is that we will call that and updte the low and chcek wehter it is the articulate point
                    if(!vis[x]){
                        Tarjan(adj,disc,low,node,vis,res,x,timer);
                        low[node]=min(low[node],low[x]);
                        if(low[x]>disc[node]){
                            vector<int> ans;
                            ans.push_back(x);
                            ans.push_back(node);
                            res.push_back(ans);
                        }
                    }
                    else {//this is condition for the back edge case and in this we will just update the low
                            low[node]=min(low[node],disc[x]);
                        }
                }

            }

vector<vector<int>> FindGraph(vector<vector<int>>& edges,int v,int e){
    //Step1 buildng the adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //Step2- making 4 vectors;
    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    int parent=-1;
    unordered_map<int,bool> vis;
    int timer=0;
    //call the dfs;
    vector<vector<int>> res;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            Tarjan(adj,disc,low,parent,vis,res,i,timer);
        }
    }
    return res;
}
int main(){
     int v = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}
    };
    int e = edges.size();

    vector<vector<int>> bridges = FindGraph(edges, v, e);

    cout << "Bridges in the graph are:\n";
    for (auto& b : bridges) {
        cout << b[0] << " -- " << b[1] << endl;
    }

    return 0;

}