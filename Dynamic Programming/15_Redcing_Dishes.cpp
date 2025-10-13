/*
Same idea as that of the kanscape
*/
#include<vector>
#include<iostream>
using namespace std;
int Reducing_dishes(vector<int>& a,int n,int time,vector<vector<int>>& dp){
    if(n==a.size()) return 0;
    if(dp[n][time]!=-1) return dp[n][time];
    int inc=a[n]*time+Reducing_dishes(a,n+1,time+1,dp);
    int exc=Reducing_dishes(a,n+1,time,dp);
    dp[n][time]= max(inc,exc);
    return dp[n][time];
}
int main(){
 vector<int> a = {-1, -8, 0, 5, -9};
    sort(a.begin(), a.end());

    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    int result = Reducing_dishes(a, 0, 1, dp);
    cout << "Maximum Like-time coefficient: " << result << endl;

    return 0;
}