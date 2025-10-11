/*
the idea here is that there is something like you can climb this or not so when you have option then you should 
think of the solution of the dp and here we will need to get the minimum cost so we will use the recursive sol
with the dp;

*/
#include<vector>
#include<iostream>
using namespace std;
int ClimbStair(int n,vector<int>& cost,vector<int>& dp){
    if(n==0){
        return cost[0];
    }
    if(n==1) return cost[1];
    if(dp[n]!=-1) return dp[n];

    dp[n]=cost[n]+min(ClimbStair(n-1,cost,dp),ClimbStair(n-2,cost,dp));
    return dp[n];
}
int main(){
 vector<int> cost = {10, 15, 20};
    int n = cost.size();

    vector<int> dp(n, -1);
    int ans = min(ClimbStair(n - 1, cost, dp), ClimbStair(n - 2, cost, dp));

    cout << "Minimum cost to reach the top: " << ans << endl;
    return 0;
}