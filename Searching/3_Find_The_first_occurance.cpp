#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int First_occur(vector<int>& a,int target){
        int low=0;
        int high=a.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
             if(a[mid]>target){
                high=mid-1;
            }
            else if(a[mid]>target){
                low=mid+1;
            }
            else {
                if(mid==0 || a[mid]!=a[mid-1]){
                    return mid;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;

    }



};