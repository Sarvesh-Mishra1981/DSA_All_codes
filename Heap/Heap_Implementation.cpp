#include<iostream>
using namespace std;
class MinHeap{
    public:
    int *arr;
    int size;
    int capacity;
    MinHeap(int c){
        arr=new int(c);
        capacity=c;
        size=0;
    }
    int left(int i){ return arr[2*i+1];}
    int right(int i){return arr[2*i+2];}
    int parent(int i){return arr[abs(i-1)/2];}
};