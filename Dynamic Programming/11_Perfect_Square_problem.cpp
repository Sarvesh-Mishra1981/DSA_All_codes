/*
We need to find the all the possible combination hence using the idea of the dp and 
in that we will run the loop
*/
#include<iostream>
#include<vector>
using namespace std;
int PerfectSq(int target,vector<int>& dp){
    if(target==0) return 0;
    if(dp[target]!=-1) return dp[target];
     int ans = target;
    for (int i = 1; i * i <= target; i++) {
        ans =min(ans, 1+PerfectSq(target - i * i, dp));
    }
    dp[target]=ans;
    return dp[target];
}
int main(){
 int target = 100; 
    vector<int> dp(target + 1, -1);

    cout << "Number of ways to form " << target << " using perfect squares: "
         << PerfectSq(target, dp) << endl;

    return 0;
}
