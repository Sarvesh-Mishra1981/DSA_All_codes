/*
we just have a simple idea that what we will do is that we will make a max and min heap and then 
we perform further operation
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void median(vector<int>& a){
    priority_queue<int> s;
    priority_queue<int, vector<int>,greater<int>> l;
    s.push(a[0]);
    for(int i=1;i<a.size();i++){
        int x=a[i];
        if(s.size()>l.size()){
            if(x<s.top()){
                l.push(s.top());
                s.pop();
                s.push(x);
            }else{
                l.push(x);
            }
            cout<<(s.top()+l.top())/2<<endl;
        }else{
            if(x<=s.top()){
                s.push(x);
            }else{
                l.push(x);
                s.push(l.top());
                l.pop();
            }
            cout<<s.top();
        }
    }
}
int main(){
    vector<int> a{25,7,10,15,12};
    median(a);
}