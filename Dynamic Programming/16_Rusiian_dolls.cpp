/*
The concept of the russian dolls is that we will traverse the arrya nd we will go to find the larger element for it 
and return that array. so it is again q of take and exclude as we can take only when it is larger or we can leave it;

*/
#include<vector>
#include<iostream>
using namespace std;
int RussianDolls(vector<int>& a,int n,int curr,int prev,vector<vector<int>>& dp){
    if(curr==n) return 0;
    int take=0;
    if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
    if(prev==-1|| a[curr]>a[prev]){
        take=1+RussianDolls(a,n,curr+1,curr,dp);
    }
    int nottake=RussianDolls(a,n,curr+1,curr,dp);
    dp[curr][prev+1]= max(take,nottake);
    return dp[curr][prev+1];
}
int main(){
  vector<int> a = {5, 4, 3, 6, 7, 8, 1};

    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    int result = RussianDolls(a, n, 0, -1, dp);
    cout << "Maximum number of Russian Dolls: " << result << endl;

    return 0;
}