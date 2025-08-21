/* to check if the strings are the rotation then we just need to do one thing that
we just write the string 2 times and just find the string in it
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool CheckTheStr(string& a,string& b){
    if(a.length()!=b.length()) return false;
    return((a+a).find(b)!=string::npos);
}
int main(){
string a="abcd";
string b="dabe";
if(CheckTheStr(a,b)) cout<<"Yes";
else cout<<"No";
}