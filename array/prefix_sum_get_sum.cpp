#include<iostream>
#include<vector>
using namespace std;
class Solution{
    vector<int> prefix_sum(vector<int>& a){
        vector<int> b;
        b[0]=a[0];
        for(int i=1;i<a.size();i++){
            b[i]=b[i-1]+a[i];
        }
        return b;
    }
    int return_sum(vector<int>& a,int l,int r){
        vector<int> b=prefix_sum(a);
        if(l==0){
            return b[r];
        }
        else return (b[r]-b[l-1]);
    }

};