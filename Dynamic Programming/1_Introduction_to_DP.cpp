/*
So what is Dp---- this is just a optimisation see the problem with the recursive solution is that in each step 
you will wait for the end step to complete and this the large time complexity so here comes the idea of the dp

So what dp does is it stores all the value that you have find and this is quite helpfull so
this thing of the dp is helpful in reducing the time complexity..

this involves 3 steps--:
1. Initialize the dp vector
2. in the recurisve sol make the thing like if(dp[i]!=-1) return dp[i];
3. store the answer in the dp and in the end return the dp[n];

This approach is the top to down aproach
and there is tabular approach where you will find the relation between 2 3 consecutive index and make the relation acc to that


*/
#include<iostream>
#include<vector>
using namespace std;
int fibonacci(int n,vector<int>& dp){
    if(n==0 || n==1) return n;

    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
    return dp[n];
}
int main(){
    int n=6;
    vector<int> dp(n+1,-1);
    cout<<fibonacci(n,dp)<<endl;

}


/*
Here is the tabular implementation and in this as i said that in this
we need to find the relation in between the index and then we just run the for loop 

int fibonacci(int n){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
    dp[n]=dp[n-1]+dp[n-2];
    }
    return dp[n];
}
*/