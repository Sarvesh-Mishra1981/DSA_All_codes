/*
This is taotall based on the observation and here we are just writing the sol
*/
#include<vector>
#include<iostream>
using namespace std;
int solve(int n,int k,vector<int>& dp){
    if(n==1) return k;
    if(n==2){
        return k*k;
    }
    if(dp[n]!=-1) return dp[n];
    dp[n]=(solve(n-2,k,dp)*(k-1))+(solve(n-1,k,dp)*(k-1));
    return dp[n];
}
int main() {
    int n = 4;  
    int k = 3;  

    vector<int> dp(n + 1, -1);
    cout << "Number of ways to paint the fence: " << solve(n, k, dp) << endl;

    return 0;
}