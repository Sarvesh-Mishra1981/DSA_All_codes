/*
This is the part 2 and here we can can hold max one stock and have the limit of 2
hence we will make one variable buy and if it is true then we will add and same thing as include and exclude
*/
#include<vector>
#include<iostream>
using namespace std;
int buyAndSell(vector<int>& a,int index,bool buy,int limit,vector<vector<vector<int>>>& dp){
    if(index==a.size()) return 0;
    if(limit==0) return 0;
    int profit=0;
    if(dp[index][buy][limit]!=-1) return dp[index][buy][limit];
    if(buy){
       int buy=-a[index]+buyAndSell(a,index+1,false,limit,dp);
       int notBuy=buyAndSell(a,index+1,true,limit,dp);
        profit=max(buy,notBuy);
    }
    else {
        int sell=a[index]+buyAndSell(a,index+1,true,limit-1,dp);
        int notsell=buyAndSell(a,index+1,false,limit,dp);
        profit=max(sell,notsell);
    }
   dp[index][buy][limit]=profit;
    return dp[index][buy][limit];
}
int main(){
  vector<int> prices = {7, 1, 5, 3, 6, 4};
    int k = 2;

   
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));

    int maxProfit = buyAndSell(prices, 0, true, k, dp);

    cout << "Maximum Profit (at most " << k << " transactions): " << maxProfit << endl;

    return 0;
}