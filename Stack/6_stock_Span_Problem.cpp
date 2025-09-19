#include<iostream>
#include<stack>
using namespace std;
//the stock span means that the number of the elemnts before were small of that element so its implemenatation is quite simple and using stack
void solve(vector<int>& a,int n){
    stack<int> s;
    vector<int> ans;
    s.push(0);
    cout<<1<<" ";
    for(int i=1;i<n;i++){
        while(!s.empty() && a[s.top()]<=a[i]){
            s.pop();
        }
        int span= s.empty()?i+1:i-s.top();
        cout<<span<<" ";
    s.push(i);      
  }
}

int main () 
{
    vector<int> a{13,15,12,14,16,8,5,4,10,30};
    solve(a,a.size());
    return 0; 
}