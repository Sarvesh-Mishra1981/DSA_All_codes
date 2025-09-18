#include<iostream>
#include<vector>
using namespace std;
class Stack{
    public:
    vector<int> v;
    void push(int x){
        v.push_back(x);
        }
    int pop(){
        if(v.empty()) return -1;
        int res=v.back();
        v.pop_back();
        return res;
    }   
    bool Isempty(){
        return v.empty();
    } 
    int size(){
        return v.size();
    }
    int peek(){
        if(v.empty()) return -1;
        return v.back();
    }

};
int main(){
 Stack s;
  s.push(10);
  s.push(20);
  s.push(10);

  cout<<s.size()<<endl;

  s.pop();
  cout<<s.peek()<<endl;
  cout<<s.size();

  return 0;
}