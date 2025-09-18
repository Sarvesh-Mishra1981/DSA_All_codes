#include<iostream>
using namespace std;
class Stack{
    public:
    int cap;
    int top;
    int* arr;
    Stack(int c){
        cap=c;
        top=-1;
        arr=new int[cap];
    }
    void push(int x){
        if(top==cap-1){return;}
        top++;
        arr[top]=x;
    }
   int pop(){
        if(top==-1) return -1;
        int res=arr[top];
        top--;
        return res;
    }
    bool isEmpty(){
        if(top==-1) return true;
        else return false; 
    }
    int peek(){
        if(top==-1) return -1;
        return arr[top];
    }
    int size(){
        return top+1;
        }
};
int main(){
    Stack s(5);
  s.push(10);
  s.push(20);
  s.push(10);

  cout<<s.size()<<endl;

  s.pop();
  cout<<s.peek()<<endl;
  cout<<s.size();

  return 0;
}