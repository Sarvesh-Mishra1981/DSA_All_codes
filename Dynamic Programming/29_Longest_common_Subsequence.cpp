/*
In this we need to find the longest common subsequence and in which we need to find the longest 
subsequence. so whts the basic idea is that if we will find the a[i]==b[j] then we will increase the 
ans by one and call the i+1 and j+1 and if we dont find then we will take max((i+1,j), (i,j+1));
*/
#include<iostream>
#include<vector>
using namespace std;
int LongestCommonSubseq(int i,int j,vector<int>& a,vector<int>& b,vector<vector<int>>& dp){
    if(i==a.size()) return 0;
    if(j==b.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(a[i]==b[j]) {
        ans+=(1+LongestCommonSubseq(i+1,j+1,a,b,dp));
    }
    else {
        ans+=max(LongestCommonSubseq(i+1,j,a,b,dp),LongestCommonSubseq(i,j+1,a,b,dp));
    }
    dp[i][j]=ans;
    return dp[i][j];
}
int main(){
  vector<int> a = {1, 3, 4, 1, 2, 3};
    vector<int> b = {3, 4, 1, 2, 1, 3};

    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans = LongestCommonSubseq(0, 0, a, b, dp);
    cout << "Length of Longest Common Subsequence: " << ans << endl;

    return 0;
}