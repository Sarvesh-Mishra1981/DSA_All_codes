#include<iostream>
using namespace std;
#include<vector>
class Solution{
    int largest(vector<int>& arr){
        int n=arr.size();
        int res=0;
        for(int i=0;i<n;i++){
            if(arr[i]>arr[res]){
                res=i;
            }
        }
        return arr[res];
    }
};