/*
In this we need to find the minimum number ofthe coins and to obtain this we will use the idea of the Dp
*/
#include<iostream>
#include<vector>
using namespace std;
int solveRec(vector<int>& coins,int x,vector<int>& dp){
    if(x==0){
        return 0;
    }
    if(x<0) return INT_MAX;
    int mini=INT_MAX;
    if(dp[x]!=-1){
        return dp[x];
    }
    for(int i=0;i<coins.size();i++){
        int ans=solveRec(coins,x-coins[i],dp);
        if(ans!=INT_MAX){
            mini=min(mini,ans);
        }
    }
    dp[x]=mini;
    return mini;
}
int solve(vector<int>& a,int x){
    int n=a.size();
    vector<int> dp(n+1,-1);
    int ans=solveRec(a,x,dp);
    if(ans==INT_MAX) return -1;

    return ans;
}
int main(){
  vector<int> coins = {1, 2, 5}; 
    int x = 11;                 

    int result = solve(coins, x);

    cout << "Coins: ";
    for (int c : coins) cout << c << " ";
    cout << "\nTarget = " << x << endl;

    if (result == -1)
        cout << "Not possible to form target sum." << endl;
    else
        cout << "Minimum coins required = " << result << endl;

    return 0;
}