#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int Lengthofevenodd(vector<int>& a){
        int n=a.size();
        int len=0;
        for(int i=1;i<n;i++){
            if(a[i]%2==0 && a[i-1]%2!=0 ||(a[i]%2!=0 && a[i-1]%2==0)){
                len++;
            }


        }
        return len;
    }

};