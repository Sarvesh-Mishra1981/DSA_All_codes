#include<iostream>
#include<vector>
using namespace std;
class Solution{
    vector<int> prefix_sum(vector<int>& a){
        vector<int> b(a.size());
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

// vector<int> sums;
    // for(int i=0; i<n; i++){
    //     int curr = 0;
    //     for(int j=i; j<n; j++){
    //         curr += nums[j];
    //         sums.push_back(curr);
    //     }
    // } this is another methor dof findig the subaaray with no repeted array;