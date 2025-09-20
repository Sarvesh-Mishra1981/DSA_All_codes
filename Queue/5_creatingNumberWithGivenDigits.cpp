#include<iostream>
using namespace std;
#include<queue>
void cretingNumWithGivenDigits(int n,int m,int k){
    queue<int> q;
    q.push(n);
    q.push(m);
    for(int i=0;i<k;i++){
        int num1=q.front();
        cout<<num1<<" ";
        q.pop();
        q.push((num1*10)+n);
         q.push((num1*10)+m);
    }
}
int main(){
    int n=5,m=6,k=10;
    cretingNumWithGivenDigits(n,m,k);
}