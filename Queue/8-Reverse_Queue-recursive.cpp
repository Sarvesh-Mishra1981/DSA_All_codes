#include<iostream>
using namespace std;
#include<queue>
#include<stack>
void ReverseIt(queue<int>& q){
    if(q.empty()) return;
    int x=q.front();
    q.pop();
    ReverseIt(q);
    q.push(x);
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