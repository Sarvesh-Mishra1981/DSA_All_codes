/*
To find the K largest elements what we do is that we make the min heap and then we jsut compare the top element amd then we just
see that if elements is greter than the top then we pop that and add that element in that 
We have not used the max heap because time complexity of max is -O(n+klogn) and of min heap we have complexity of the O(k+(n-k)logk)
as in the max we need to travese the whole array then we need to push n elemnts and run loop to find the k elements
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void KLargest(vector<int>& a,int k){
    int n=a.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(a[i]);
    }
    for(int i=k;i<n;i++){
        if(pq.top()<a[i]){
            pq.pop();
            pq.push(a[i]);
        }
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
int main(){
    vector<int> a{ 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
    KLargest(a,3);
}