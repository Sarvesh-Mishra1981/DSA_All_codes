/*
So the basic idea here is that we need to find the max points of foeming the traingle
so what we will do is that we will seleect the 2 points and then traverse and select all the points 
hence we will usethe idea of the dp
The value of the traingle is then product of its vertices and the sumof all these is the cost of the traingulation
*/
#include<iostream>
#include<vector>
using namespace std;
int MinScore(vector<int>& v,int i,int j,vector<vector<int>>& dp){
    if(i+1==j) return 0;//as we need 3 points so if this happens then there are only 2 points and this is not possible
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        ans=min(ans,v[i]*v[k]*v[j]+MinScore(v,i,k,dp)+MinScore(v,k,j,dp));
    }
      dp[i][j]=ans;
      return dp[i][j];
}
int main(){
 vector<int> v = {1, 3, 1, 4, 1, 5};

    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << "Minimum score triangulation is: "
         << MinScore(v, 0, n - 1, dp) << endl;

    return 0;
}