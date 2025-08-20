/* in this we need to revese the whole string each characters\
to reverse the string do onething
1.reverse each word
2. when all the word are reversed then reverse the whole string

*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void reverseit(string& s,int start,int end){
    while(start<end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
}
void reverseTheString(string& s){
    int n=s.length();
    int start=0;
    int end=0;
    for(;end<s.length();end++){
        if(s[end]==' '){
            reverseit(s,start,end-1);
            start=end+1;
        }
    }
    reverseit(s,start,n-1);
    reverseit(s,0,n-1);
}
int main(){
    string s="Hello from Sarvesh";
    reverseTheString(s);
    cout<<s;
    return 0;
}