#include<iostream>
#include<vector>
using namespace std;
class Solution{
    bool pointer(vector<int>& a,int target){
        int fst=0;
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
};