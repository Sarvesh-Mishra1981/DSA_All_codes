/*
in this we need to find the minimum cost of the ticket in which you have 3option
1. Tickets for one day
2.Ticket for 7 days and u will get the pass
3. Tickets for 30 days and u will get the pass for 30 days
As we need to go thorugh all the cases hence using the idea of the dp
*/
#include<iostream>
#include<vector>
using namespace std;
int MinimumCost(vector<int>& cost,vector<int>& days,int index,vector<int>& dp,int n){
    if(index>=n) return 0;
    if(dp[index]!=-1) return dp[index];
    int a=cost[0]+MinimumCost(cost,days,index+1,dp,n);
    int i;
    for(i=index;i<n && days[i]< days[index]+7;i++);
    int b=cost[1]+MinimumCost(cost,days,i,dp,n);

    for( i=index;i<n && days[i]< days[index]+30;i++);
    int c=cost[2]+MinimumCost(cost,days,i,dp,n);

    dp[index]= min(a,min(b,c));
    return dp[index];
}
int main(){
 vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> cost = {2, 7, 15}; 
    int n = days.size();

    vector<int> dp(n, -1);

    cout << "Minimum cost of travel: "
         << MinimumCost(cost, days, 0, dp, n) << endl;

    return 0;
}