/*
Tower of Hanaoi is common problem and here it is quite simple first you have 
1. move the n-1 form. main to the helping one 
2. print the moving from the dest
3. moving the n-1  from helping to dest 
*/
#include<iostream>
using namespace std;
void TowerOfHanoi(int n,char A,char B,char C){
    if(n==0) return;
    TowerOfHanoi(n-1,A,C,B);
    cout<<A<<"->"<<C<<endl;
    TowerOfHanoi(n-1,B,A,C);
}
int main(){
int n=3;
TowerOfHanoi(n,'A','B','C');
}
// the total number of steps will be pow(2,n-1)-1;