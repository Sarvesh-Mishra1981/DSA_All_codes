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

     int Last_occur(vector<int>& a,int target){
        int low=0;
        int high=a.size()-1;
        int n=a.size();
        while(low<=high){
            int mid=(low+high)/2;
             if(a[mid]>target){
                high=mid-1;
            }
            else if(a[mid]>target){
                low=mid+1;
            }
            else {
                if(mid==n-1 || a[mid]!=a[mid+1]){
                    return mid;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return -1;

    }

    int distance(vector<int>& a){
        int start=First_occur(a,1);
        int end=Last_occur(a,1);
        return (end-start);
    }





};