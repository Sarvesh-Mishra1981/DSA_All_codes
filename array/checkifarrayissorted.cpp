#include<iostream>
#include<vector>
using namespace std;
class Solution{
    bool check(vector<int> & a){
        for(int i=0;i<a.size()-1;i++){
            if(a[i]>a[i+1]){
                return false;
            }
        }
        return true;
    }

};