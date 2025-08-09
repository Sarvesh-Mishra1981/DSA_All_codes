#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int sum(vector<int>& a,int st,int end){
        int d=0;
        for(int i=st;i<=end;i++){
            d+=a[i];
        }
        return d;
    }
    int solve(vector<int>& a,int n,int k){
        if(k==1) return sum(a,0,n-1);
        if(n==1) return a[0];
        int res=INT_MAX;
        for(int i=1;i<n;i++){
            res=min(res,max(solve(a,i,k-1),sum(a,i,n-1)));
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        return solve(nums,nums.size(),threshold);
    }
};