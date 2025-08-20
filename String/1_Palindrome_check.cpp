// the basic idea is to use 2 pointer approach and then when we find the diff element then we just return the false.
#include<iostream>
#include<string>
using namespace std;
bool IsPalindrome(string& s,int start,int end){
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int main(){
    return 0;
}