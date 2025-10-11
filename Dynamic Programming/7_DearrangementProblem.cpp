/*
Dearrangement means that how much u can displace a block of elements so
if we choose one block then we have n-1 ways to arrange that and if we choose the 2 block to swap to one another then we have 
n-2 blocks as opion so using that idea;
*/
#include<iostream>
#include<vector>
using namespace std;
int solve(int n,vector<int>& dp){
    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n]= (n-1)*(solve(n-1,dp)+solve(n-2,dp));
    return dp[n];
}
int solveRec(int n){
    vector<int> dp(n+1,-1);
    int ans=solve(n,dp);
    return ans;
}
int main(){
  int n = 5; 
    cout << "Number of derangements for n = " << n << " is " << solveRec(n) << endl;

    for (int i = 1; i <= 6; i++) {
        cout << "n = " << i << " -> Derangements = " << solveRec(i) << endl;
    }

    return 0;
}