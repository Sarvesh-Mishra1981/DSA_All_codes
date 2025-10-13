/*
In this we need to find the all the possible pathway to do this so we will
use the loop in the idea of the dp
*/
#include<iostream>
#include<vector>
using namespace std;
int TargetWithDice(int dices,int target,int faces,vector<vector<int>>& dp){
    if (target < 0) return 0;
    if(target==0 && dices==0) return 1;
    if(target!=0&& dices==0) return 0;
    if(target==0 && dices!=0) return 0;
    int ans=0;
    if(dp[dices][target]!=-1) return dp[dices][target];
    for(int i=1;i<=faces;i++){
        ans+=TargetWithDice(dices-1,target-i,faces,dp);
    }
    dp[dices][target]=ans;
    return dp[dices][target];
}
int main(){
int dices = 3;  // number of dice
    int faces = 6;  // number of faces per die
    int target = 7; // target sum

    // Initialize DP table
    vector<vector<int>> dp(dices + 1, vector<int>(target + 1, -1));

    int ways = TargetWithDice(dices, target, faces, dp);
    cout << "Number of ways to get sum " << target << " with " << dices 
         << " dice of " << faces << " faces: " << ways << endl;

    return 0;
}