#include<iostream>
using namespace std;
void PrintIt(int n){
    if(n==0) return ;
    cout<<n<<" ";
    PrintIt(n-1);
}
int main(){
int n=10;
PrintIt(n);
}