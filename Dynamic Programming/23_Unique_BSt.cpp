/*
in ths you need to count the number of the unique bst you can form so in this we need to use that premutation idea 
we need to go to left and think we can reagrrange them in i-1 steps and in the right we can rearragnge in n-i steps and 
the answer for that i is the product of each and we need to find the sum of all such products for the n size array

*/
#include<iostream>
#include<vector>
using namespace std;
int unique_BST(int n,vector<int>& dp){
    if(n<=1) return 1;
    int ans=0;
    if(dp[n]!=-1) return dp[n];
    for(int i=1;i<=n;i++){
        ans+=unique_BST(i-1,dp)*unique_BST(n-i,dp);
    }
    dp[n]=ans;
    return dp[n];
}
int main(){
    int n=4;
    vector<int> dp(n+1,-1);
    cout<<unique_BST(n,dp)<<endl;
}