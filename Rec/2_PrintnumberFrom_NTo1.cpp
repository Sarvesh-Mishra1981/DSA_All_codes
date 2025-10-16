#include<iostream>
using namespace std;
void PrintIt(int n){
    if(n==0) return;
    PrintIt(n-1);
    cout<<n<<" ";
}
int main(){
int n=10;
PrintIt(n);
}