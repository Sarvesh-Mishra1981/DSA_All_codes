/* 
In this algo the idea is that we will run the loop for the n-1 times and in each iteration will go to all the edges 
and upadte the ditance one benefit is that it can handle the negativevalue as well
and u have just to chcek that weather the grap does not begin a negative cycle 
to check that we will run the loop for 1 time after the n-1 times if the distance still updates then it is neagtive cycle and hence it is not possible
*/
#include<iostream>
#include<vector>
using namespace std;
int  BellmanFord(vector<vector<int>>& a,int n,int edges,int s,int destination){
    vector<int> dis(n,INT_MAX);
    dis[s]=0;
    //run the loop for n-1 times
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<edges;j++){
            int u=a[j][0];
            int v=a[j][1];
            int wt=a[j][2];
            if(dis[u]!=INT_MAX && ((dis[u]+wt)<dis[v])){
                dis[v]=dis[u]+wt;
            }
        }
    }
    //Now check for the negative loop for that we will run the loop for 1 time and if diastance chnges then yes it is negative cycle
    bool flag=false;
    for(int j=0;j<edges;j++){
            int u=a[j][0];
            int v=a[j][1];
            int wt=a[j][2];
            if(dis[u]!=INT_MAX && ((dis[u]+wt)<dis[v])){
                flag=true;
            }
        }
        if(flag) return -1;
        else return dis[destination];
}
int main(){
  int n = 4; // number of vertices
    int edges = 5;
    vector<vector<int>> a = {
        {0, 1, 4},
        {0, 2, 5},
        {1, 2, -3},
        {1, 3, 2},
        {2, 3, 4}
    };

    int src = 0, dest = 3;
    int result = BellmanFord(a, n, edges, src, dest);
    if(result != -1){
        cout << "Shortest distance from " << src << " to " << dest << " is " << result << endl;
    }

    return 0;
}