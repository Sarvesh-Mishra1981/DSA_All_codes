/*
In the kanscape you need to find the max amount that you can acheive within the constraint..
sowill use the idea of the include and exclude and will include if it has cost less than capacity
here we will introduce the 2 index dp as it has changing the index as well as capacity
*/
#include<vector>
#include<iostream>
using namespace std;
int kanscape(int n,int capacity,vector<int>& value,vector<int>& weight,vector<vector<int>>& dp){
    if(n==0){
        if(capacity>=weight[0]){
            return value[0];
        }
        else return 0;
    }
    if(dp[n][capacity]!=-1) return dp[n][capacity];
    int inc;
    if(weight[n]<=capacity){
        int inc=value[n]+kanscape(n-1,capacity-weight[n],value,weight,dp);
    }
    int exc=kanscape(n-1,capacity,value,weight,dp);
    dp[n][capacity]=max(exc,inc);
    return  dp[n][capacity];
}
int main(){
  vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50;
    int n = value.size();

    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

    cout << "Maximum value that can be obtained: " 
         << kanscape(n - 1, capacity, value, weight, dp) << endl;

    return 0;
}