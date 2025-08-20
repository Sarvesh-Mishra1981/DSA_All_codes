/* 
the idea is that we put the elemnt in the vcetor of bool basically the idea is the Sieve Of Eranthesis and we travese from the end so that
the first elemnt gets overwrite 
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int leftmost(string& a){
    int n=a.length();
    int res=-1;
    vector<bool> c(26,false);
    for(int i=a.length()-1;i>=0;i--){
        if(c[a[i]-'a']) {
            res=i;
        }else
        {c[a[i]-'a']=true;}
    }
    return res;
}
int main(){
    string s="sarvesh";
    cout<<leftmost(s);
    return 0;
}