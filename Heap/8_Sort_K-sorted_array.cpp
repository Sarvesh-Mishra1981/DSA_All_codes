/*
the idea is that we will use the prioirity queue and here we will add the elements and there we will use the
idea of the sliding window and find the min*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> SortKSoretd(vector<int>& a,int k){
    int n=a.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<=k;i++){
        pq.push(a[i]);
    }
    int index=0;
    vector<int> res(n);
    for(int i=k+1;i<n;i++){
        res[index++]=pq.top();
        pq.pop();
        pq.push(a[i]);
    }
    while(!pq.empty()){
        res[index++]=pq.top();
        pq.pop();
    }
    return res;
}
int main(){
    vector<int> a{10,9,7,8,4,70,50,60};
    vector<int> res=SortKSoretd(a,4);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}