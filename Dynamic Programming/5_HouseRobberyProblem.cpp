/*
In this the question says that we cannot rob the adjacent house and houses are in circular fashion. So if we rob the 
1st house then we cannot rob the last house and similary if we rob the last house then we cannot rob the 1st house

So we used this process--;
1. make the vector of 0 to n-2 and find the max non adj sum
2.make the vector of 1 to n-1 and thne find the max non adj sum
and return the max of these;

*/
#include<vector>
#include<iostream>
#include<climits>
using namespace std;
int solveRec(vector<int>& a,int n,vector<int>& dp){
    if(n<0) return 0;
    if(n==0) return a[0];
    if(dp[n]!=-1) return dp[n];

    int inc=a[n]+solveRec(a,n+2,dp);
    int exc=solveRec(a,n+1,dp);
    dp[n]= max(inc,exc);
    return dp[n];
}
int solve(vector<int>& a){
int n=a.size();
if (n == 1) return a[0];
vector<int> dp1(n,-1);
vector<int> dp2(n,-1);
vector<int> b(a.begin(),a.end()-1);
vector<int> c(a.begin() + 1, a.end());

    int case1 = solveRec(b, b.size() - 1, dp1);
    int case2 = solveRec(c, c.size() - 1, dp2);

    return max(case1, case2);
}

int main(){
vector<int> houses = {2, 3, 2}; 
    int result = solve(houses);

    cout << "Houses: ";
    for (int x : houses) cout << x << " ";
    cout << "\nMaximum amount that can be robbed = " << result << endl;

    return 0;
}