/*
the idea is that in toposort just think that the if there is cycle then the point having the cycle uski indegree will never become zero
hence it ewill never be inserted in the queue and we will use thus what we will do is that 
we will increment the count only when we will remove the element from the queue and in the end we will compare it with the 
number of vertices

*/
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
bool DetectCycle(vector<int> adj[],int v){
    int count=0;
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
        q.pop();
        count++;
        for(auto x:adj[u]){
            if(--indgree[x]==0){
                q.push(x);
            }
        }
    }
    return (count==v);

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
    if(DetectCycle(adj,V)) cout<<"Yes";
    else cout<<"No"<<endl;

	return 0; 
}
