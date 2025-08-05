#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int SubWithGivenSum(vector<int>& a,int n,int k){
        //we are using the idea of the sliding window
        int sum=0;
        int maxi=0;
        for(int i=0;i<k;i++){
            sum+=a[i];
       }
       for(int i=k;i<a.size();i++){
        sum+=a[i]-a[i-k];
        maxi=max(maxi,sum);
       }
       return maxi;
    }
};