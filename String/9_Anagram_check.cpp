/* in this we are give. along string nad we need to check the anagram in it 
the idea we are using is that we store the num of elements and then we will kust cmpare both the strings
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool CheckTheAnagram(string& a,string& b){
    int n=a.length();
    int m=b.length();
    vector<int> s(256,0);
    vector<int> r(256,0);
    for(int i=0;i<m;i++){
        s[a[i]]++;
        r[b[i]]++;
    }
    for(int i=m;i<n-m;i++){
        if(s==r) return true;
            s[a[i-m]]--;
            s[a[i]]++;
    }
    return false;
}
int main(){
string a="bcdabcdereg";
string b="ac";
if(CheckTheAnagram(a,b)) cout<<"Yes";
else cout<<"No";
}