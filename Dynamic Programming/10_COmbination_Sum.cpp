/*
This is a very good algo for just determine the all the possible combination of the sum
for the recursion you should have onr base condition and just think of one case
 baki recursion dekh lega.
 Here we have used the loop jo ki baar baar har possible condition nikal lega 
*/
#include<iostream>
#include<vector>
using namespace std;
int Combination_Sum(vector<int>& nums,vector<int>& dp,int target){
    if(target<0){
        return 0;
    }
    if (target==0) return 1;
    if(dp[target]!=-1) return dp[target];
    int sum=0;
    for(int i=0;i<nums.size();i++){
        //here it will find all the possible combaination 
        sum+=Combination_Sum(nums,dp,target-nums[i]);
    }
    dp[target]=sum;
    return dp[target];
}
int main(){
 vector<int> nums = {1, 2, 3}; // numbers to use
    int target = 4;               // target sum

    vector<int> dp(target + 1, -1);

    cout << "Total combinations to reach target = " 
         << Combination_Sum(nums, dp, target) << endl;

    return 0;
}