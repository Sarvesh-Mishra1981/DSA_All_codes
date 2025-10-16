#include<iostream>
using namespace std;
bool PalindromeCheck(string s,int start,int end){
    if(start>=end) return true;
    return(s[start]==s[end] && PalindromeCheck(s,start+1,end-1));
}
int main(){
 string str = "madam";  

    if (PalindromeCheck(str, 0, str.length() - 1))
        cout << str << " is a palindrome." << endl;
    else
        cout << str << " is not a palindrome." << endl;

    return 0;
}