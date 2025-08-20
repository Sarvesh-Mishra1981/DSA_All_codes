/*
So the anagram is the permutation of the string and hence we can say that we will have the same number of the elements and 
same elements and hence we will work on the same logic

either we can just create vector and in one string we will just increase the count
and in the other string we will decrease the count if at the end count of any num is >0 then it is false;
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool IsAnagram(string& a,string& b){
    int n=a.length();
    if(n!=b.length()) return false;
    vector<int> m(n,0);
    for(int i=0;i<n;i++){
        m[a[i]-'a']++;
        m[b[i]-'a']--;
    }
    for(int i=0;i<m.size();i++){
        if(m[i]>0) return false;
    }
    return true;
}
int main(){
    string a="listen";
    string b="silten";
    if(IsAnagram(a,b)) cout<<"yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}