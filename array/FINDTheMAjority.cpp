#include<iostream>
#include<vector>
using namespace std;
class Solution{
void findTheMajority(vector<int>& a,int k){
        unordered_map<int,int> m;
        for(int i=0;i<a.size();i++){
            m[a[i]]++;
        }
        for(auto p:m){
            if(p.second>k){
                cout<<p.first<<endl;
            }
        }
    }


};