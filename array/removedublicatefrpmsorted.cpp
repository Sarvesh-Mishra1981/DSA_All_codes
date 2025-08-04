#include<iostream>
#include<vector>
using namespace std;
class Solution{
    vector<int> solve(vector<int>& a){
        vector<int> temp;
        int res=1;
        for(int i=0;i<a.size();i++){
            if(temp[res-1]!=a[i]){
                temp[res]=a[i];
                res++;
}
        }
        return temp;
    }

};