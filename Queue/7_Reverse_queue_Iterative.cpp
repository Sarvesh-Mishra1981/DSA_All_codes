#include<iostream>
using namespace std;
#include<queue>
#include<stack>
void ReverseIt(queue<int>& a){
stack<int> s;
while(!a.empty()){
s.push(a.front());
a.pop();
}
while(!s.empty()){
    a.push(s.top());
    s.pop();
}
}
int main(){
    deque<int> d = {1, 2, 3, 4, 5, 6};
    queue<int> q(d);
    ReverseIt(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

}