#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int Binary_search(vector<int>& a,int target,int low,int high){
        int mid=(high+low)/2;
        if(a[mid]==target){
            return mid;
        }
        else if(a[mid]>target){
            Binary_search(a,target,low,mid-1);
        }
        else{
            Binary_search(a,target,mid+1,high);
        }
       return -1;
    }


};