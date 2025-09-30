/*
this is just a basic info of the priority queue and the sitl function of it 
SO the priority queue is buld on the vectors but it uses the concept of the heap 
push and pop operation takes 0(logn) time and top and otre opertaion takes O(1)
the priority queue is max heap by default and we can convert it into min heap;
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(5);
    cout<<pq.top()<<" ";
    pq.pop();
    cout<<pq.top()<<" ";


    // here comes the min heap
    priority_queue<int,vector<int>,greater<int>> pr;
     pr.push(10);
    pr.push(20);
    pr.push(30);
    pr.push(5);
    cout<<pr.top()<<" ";
    pr.pop();
    cout<<pr.top();

    return 0;
}