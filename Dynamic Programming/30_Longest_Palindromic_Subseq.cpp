/*
This is same as the last q and in this what we will do is that we will revert the vector and and check for the 
common subseq and if the length of the common subseq is equal to length of the longest Palindromic subseq.
*/
#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a,vector<int>& rev_a,int i,int j,vector<vector<int>>& dp){
    if(i==a.size()) return 0;
    if(j==a.size()) return 0;
    int ans=0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==rev_a[j]){
        ans=1+solve(a,rev_a,i+1,j+1,dp);
    }
    else {
        ans=max(solve(a,rev_a,i+1,j,dp),solve(a,rev_a,i,j+1,dp));
    }
   dp[i][j]=ans;
   return dp[i][j];
}   
int PalindromicSubseq(vector<int>& a) {
    vector<int> rev_a = a;
    reverse(rev_a.begin(), rev_a.end());

    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solve(a, rev_a, 0, 0, dp);
}

int main() {
    vector<int> a = {1, 2, 3, 2, 1};

    cout << "Length of Longest Palindromic Subsequence: "
         << PalindromicSubseq(a) << endl;

    return 0;
}