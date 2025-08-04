#include<iostream>
#include<vector>
using namespace std;
class Solution{
    void reverseit(vector<int>& a,int start,int end){
        while(start<end){
            swap(a[start],a[end]);
            start++;
            end--;
        }
    }
    void LeftRotateByd(vector<int>& a,int d){
        //the idea is that we do the reverse 0 to d-1 then from d to n then from 0-n
        int n=a.size();
        reverseit(a,0,d-1);
        reverseit(a,d,n-1);
        reverseit(a,0,n-1);
    }
};