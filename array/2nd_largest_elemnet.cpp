#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int second_finder(vector<int>& a){
        int res=-1;
        int largest=0;
        for(int i=0;i<a.size();i++){
            if(a[i]>a[largest]){
                largest=i;
            }
            else if(a[i]!=a[largest]){
                if(res==-1 || a[i]>a[res]){
                    res=i;
                }
            }
        }
        return res;
    }

};