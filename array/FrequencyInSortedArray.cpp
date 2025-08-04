#include<iostream>
#include<vector>
using namespace std;
class Solution{
    void Frequency(vector<int>& a){
        unordered_map<int,int> m;
        for(int i=0;i<a.size();i++){
            m[a[i]]++;
        } 
        for(auto& p:m){
            cout<<p.first<<"The freq is"<<p.second<<endl;
        }

    }


};