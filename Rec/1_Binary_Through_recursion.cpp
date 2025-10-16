/*
In this we need to find the binary of any number as we know the bianry is nothing but the reverse of its %2  till the
digit becomes 0
*/
#include<vector>
#include<iostream>
using namespace std;
void Binary(int n){
    if(n==0) return;
    Binary(n/2);
    cout<<n%2<<" ";
}
int main(){
    int n=2;
    Binary(n);
}