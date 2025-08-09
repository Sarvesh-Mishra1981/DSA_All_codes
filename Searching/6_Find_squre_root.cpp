#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int find_sq(int n){
        int low=0;
        int high=n;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            int msq=mid*mid;
            if(msq==n) return mid;
            else if(msq>n){
                high=mid-1;
            }
            else {
                low=mid+1;
                ans=mid;
            }
        }
        return ans;
    }
};