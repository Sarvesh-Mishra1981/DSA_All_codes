#include<iostream>
using namespace std;
class Queue{
    int cap,size;
    int *arr;
    Queue(int c){
        cap=c;
        size=0;
        arr= new int[cap];
    }
    bool isFull(){
        return (cap==size);
    }
    bool Isempty(){
        return (size==0);
    }
    void enqueue(int x){
        if(isFull()) return;
        arr[size]=x;
        size++;
    }
    void dequeue(){
        if(Isempty()) return;
        for(int i=0;i<size-1;i++){
            arr[i]=arr[i+1];
        }
        size--;
    }
    int getFront(){
        if(Isempty()) return -1;
        else return arr[0];
    }
    int getback(){
        if(isFull()) return -1;
        else return arr[size-1];
    }
};
int main(){
    
}