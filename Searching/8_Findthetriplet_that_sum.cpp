#include<iostream>
#include<vector>
using namespace std;
class Solution{
    bool pointer(vector<int>& a,int target,int st){
        int fst=st;
        int end=a.size()-1;
        while(fst<=end){
            if(a[end]+a[fst]==target) return true;
            else if(a[end]+a[fst] >target){
                end--;
            }
            else {
                fst++;
            }
        }
        return false;
    }
    bool triplet_with_sum(vector<int>& a,int x){
        for(int i=0;i<a.size()-2;i++){
            if(pointer(a,x-a[i],i+1)){return true;}
        }
        return false;
    }
};