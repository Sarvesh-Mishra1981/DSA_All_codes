#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int getWater(vector<int>& a,int n){
    int res=0;
    vector<int> lmax(n);
    vector<int> rmax(n);
    lmax[0]=a[0];
    rmax[n-1]=a[n-1];
    for(int i=1;i<a.size();i++){
        lmax[i]=max(lmax[i-1],a[i]);
    }
    for(int i=n-2;i>=0;i--){
        rmax[i]=max(rmax[i+1],a[i]);
    }
    for(int i=1;i<n-1;i++){
        res+=min(lmax[i],rmax[i])-a[i];
    }
        return res;
    }

};