/* the idea is to check that if the 2nd string is subsequence of other or not 
the plan is to traverse the from the end of the string and then what we will do is that we just pass the 
last find pos and the acc we write the code
*/
#include<iostream>
#include<string>
using namespace std;
bool IsSubsequence(string& a,string& b,int n,int m){
    if(m==0) return true;       // empty subsequence always matches
    if(n==0) return false;      // a finished but b not finished
    if(a[n-1]==b[m-1])
        return IsSubsequence(a,b,n-1,m-1);
    else
        return IsSubsequence(a,b,n-1,m);
}
using namespace std;
int main(){
    string s="abcde";
    string b="abd";
    cout<<IsSubsequence(s,b,s.length(),b.length());
    return 0;
}