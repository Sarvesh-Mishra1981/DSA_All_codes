/*
Ypu will be provded by the sum of the elemets and you hve to find the max number of elemnts you can buy so idea 
is thta u will sort the srray in the basis of the min and then find the num of elements
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int maxElementsThatCanBuy(vector<int>& a,int sum){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<a.size();i++){
        pq.push(a[i]);
    }
    int res=0;
    for(int i=0;i<a.size();i++){
        if(sum>=pq.top()){
            sum-=pq.top();
            pq.pop();
            res++;
        }else{
            break;
        }
    }
    return res;
}
int main(){
    vector<int> a{1,12,5,111,200};
    cout<< maxElementsThatCanBuy(a,10);
}