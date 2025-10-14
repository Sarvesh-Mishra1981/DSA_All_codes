/*
In this we will play the game and then if we will guess the number then we will be win
and then if we are wrong then then we need to pay that guessed number and u need to
find the min cost so that we could win hence we will iterate through all vector element
*/
#include<vector>
#include<iostream>
using namespace std;
int MinCost(int start,int end,vector<vector<int>>& dp){
    if(start>=end) return 0;
    int mini=INT_MAX;
    if(dp[start][end]!=-1) return dp[start][end];
    for(int i=start;i<end;i++){
        mini=min(mini,i+max(MinCost(start,i-1,dp),MinCost(i+1,end,dp)));
    }
    dp[start][end]=mini;
    return dp[start][end];
}
int main(){
    int n=5;
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    cout<<MinCost(1,n,dp)<<endl;
}