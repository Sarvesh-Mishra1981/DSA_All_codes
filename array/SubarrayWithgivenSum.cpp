#include<iostream>
#include<vector>
using namespace std;
class Solution{
    bool SubWithGivenSum(vector<int>& a,int sum,int k){
        int s=0;
        int j=0;
        for(int i=0;i<a.size();i++){
            s+=a[i];
            if(s==sum) return true;
            while(s>sum){
                s=s-a[j];
                j++;

            }
                
        }
        return false;
    }
};