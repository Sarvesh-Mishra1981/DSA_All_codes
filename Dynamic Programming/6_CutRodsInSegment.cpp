/*
In this we are given 3 segments and we are asked that what is max number of the segmenets we can obtain
so basic idea is same we will make all the cases and then find the max to reduce the complexity
we will use the idea of the dp . 
*/
#include<vector>
#include<iostream>
using namespace std;
int solveRec(int l,int x,int y,int z,vector<int>& dp){
    if(l==0) return 0;
    if(l<0) return INT_MIN;
    if(dp[l]!=-1) return dp[l];
    int a=solveRec(l-x,x,y,z,dp)+1;
    int b=solveRec(l-y,x,y,z,dp)+1;
    int c=solveRec(l-z,x,y,z,dp)+1;
    dp[l]= max(a,max(b,c));
    return dp[l];
}
int solve(int l,int x,int y,int z){
vector<int> dp(l+1,-1);
int ans=solveRec(l,x,y,z,dp);
if(ans==INT_MIN) return 0;
return ans;
}
int main(){
int l = 7, x = 5, y = 2, z = 2;

    cout << "Rod length = " << l << endl;
    cout << "Possible segment lengths = " << x << ", " << y << ", " << z << endl;

    int result = solve(l, x, y, z);

    cout << "Maximum number of segments = " << result << endl;

    return 0;
}