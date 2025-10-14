/*
You have to partition the equal nuber of the subets so if the number of the elements is odd then this is not possible 
in this it is same as that to target sum as here the target will be the all sum/2
so using the idea of the dp along with the recursion
*/
#include<iostream>
#include<vector>
using namespace std;
bool PartitionSet(vector<int>& a,int target,int index,int n,vector<vector<int>>& dp){
    if(index>=n) return 0;
    if(target<0) return 0;
    if(target==0) return 1;
    if(dp[index][target]!=-1) return dp[index][target];
    bool inc=PartitionSet(a,target-a[index],index+1,n,dp);
    bool ex=PartitionSet(a,target,index+1,n,dp);
    dp[index][target] =(inc || ex);
    return dp[index][target];
}
bool EqualSet(vector<int>& a){
    int n=a.size();
    int total=0;
    for(int i=0;i<n;i++){
        total+=a[i];
    }
    int target=total/2;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return PartitionSet(a,target,0,n,dp);
}
int main(){
 vector<int> a = {1, 5, 11, 5};
    if (EqualSet(a)) cout << "Can be partitioned equally.\n";
    else cout << "Cannot be partitioned equally.\n";
}