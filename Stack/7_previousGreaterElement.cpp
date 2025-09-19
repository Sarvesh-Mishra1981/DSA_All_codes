#include<iostream>
#include<stack>
using namespace std;
//previous greter element is just we neeed to remove the smaller element than the a[i] in the stack;
void solve(vector<int>& a,int n){
    stack<int> s;
    vector<int> ans;
    s.push(a[0]);
    cout<<-1<<" ";
    for(int i=1;i<n;i++){
        while(!s.empty() && s.top()<=a[i]){
            s.pop();
        }
        int span= s.empty()?-1:s.top();
        cout<<span<<" ";
    s.push(a[i]);      
  }
}

int main () 
{
    vector<int> a{13,15,12,14,16,8,5,4,10,30};
    solve(a,a.size());
    return 0; 
}