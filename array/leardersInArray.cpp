#include<iostream>
#include<vector>
using namespace std;
class Solution{
    vector<int> Leader(vector<int>& a){
        vector<int> b;
        int n=a.size();
        int curr_leader=a[n-1];
        b.push_back(curr_leader);
        for(int i=n-2;i>=0;i--){
            if(a[i]>curr_leader){
                b.push_back(a[i]);
                curr_leader=a[i];
            }
        }
        return b;
    }

};