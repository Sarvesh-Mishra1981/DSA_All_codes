#include<iostream>
#include<vector>
using namespace std;
class Solution{
    void MoveZerosToEnd(vector<int>& a){
        int count=0;//the basic idea is that ham kya krenge ki ek count banyenge and usko tab hi aage badenge jab 1 milega 
        for(int i=0;i<a.size();i++){
            if(a[i]!=0){
                swap(a[i],a[count]);
                count++;
            }
        }
    }
};