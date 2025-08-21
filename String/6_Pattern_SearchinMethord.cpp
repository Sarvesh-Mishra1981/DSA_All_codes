/*
The idea is that we willl have 2 pointers one at jo search karna hai and other at main word and then wht we will do is that 
we compare the each elemnet and rest are the 2 condition
if
1. j is ==0 that means no elemnts gets matched then we just move i by one 
2. if some j is matched and then not mstching then we will move the i by i+j
anf if j==m then whole word is matched 
*/
#include <iostream>
#include<string>
#include<vector>
using namespace std;
bool cmpStr(string& a,string& b){
    int n=a.length();
    int m=b.length();
    for(int i=0;i<n-m;){
        int j;
        for(j=0;j<m;j++){
            if(b[j]!=a[i+j]) break;
        }
        if(j==m) return true;
        else if(j==0) i++;
        else i=i+j;
    }
    return false;
}
int main(){
string a="abcdef";
string b="cdea";
if(cmpStr(a,b)) cout<<"yes";
else cout<<"No";

}