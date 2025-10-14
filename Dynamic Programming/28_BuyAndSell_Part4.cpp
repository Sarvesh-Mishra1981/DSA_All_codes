/*
This is the part 2 and here we can can hold max one stock and have fee in each transaction
hence we will make one variable buy and if it is true then we will add and same thing as include and exclude
*/
#include<vector>
#include<iostream>
using namespace std;
int buyAndSell(vector<int>& a,int index,bool buy,int fee,vector<vector<int>>& dp){
    if(index==a.size()) return 0;
    int profit=0;
    if(dp[index][buy]!=-1) return dp[index][buy];
    if(buy){
       int buy=-a[index]+buyAndSell(a,index+1,false,fee,dp);
       int notBuy=buyAndSell(a,index+1,true,fee,dp);
        profit=max(buy,notBuy);
    }
    else {
        int sell=a[index]-fee+buyAndSell(a,index+1,true,fee,dp);
        int notsell=buyAndSell(a,index+1,false,fee,dp);
        profit=max(sell,notsell);
    }
    dp[index][buy]=profit;
    return dp[index][buy];
}
int main(){
  vector<int> prices = {7, 1, 5, 3, 6, 4};
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));

    int maxProfit = buyAndSell(prices, 0, true,2, dp);

    cout << "Maximum Profit (Multiple Transactions): " << maxProfit << endl;

    return 0;
}