/*
Here we will us ethe idea of the include and exclude and when we will include then we will not be choosing the 
next element but we will be choosing i+2 element and when we are excluding it then we choose i+1 element;
*/
#include<vector>
#include<iostream>
using namespace std;
int solve(vector<int>& n,int i,vector<int>& dp){
    if(i<0) return 0;
    if(i==0) return n[0];
    if(dp[i]!=-1) return dp[i];
    int inc=n[i]+solve(n,i+2,dp);
    int exc=solve(n,i+1,dp);
    dp[i]=max(inc,exc);
    return dp[i];
}
int main(){
    vector<int> nums = {2, 7, 9, 3, 1};
    int n = nums.size();

    vector<int> dp(n, -1);

    int result = solve(nums, n - 1, dp);

    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << "\nMaximum sum of non-adjacent elements = " << result << endl;

    return 0;

}