#include<iostream>
#include<algorithm>
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

    void insert(int x){
        if(size==capacity) cout<<"Size is full"<<endl;
        size++;
        int i = size - 1;
        arr[size-1]=x;
          while(i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void MinHeapify(int i){// this makes the graph correct and this is used in the extract min function 
        int lt=left(i);
        int rt=right(i);
        int smallest=i;
        if(lt<size && arr[i]>arr[lt]) smallest=lt;
        if(rt<size && arr[smallest]>arr[rt]) smallest=rt;
        if(smallest!=i){
            swap(arr[smallest],arr[i]);
            MinHeapify(smallest);
        }
    }
    int extractMin(){
        /* 
        The basic idea what we will be using is that we know that we top will be min and we will replace the top with last
        element and then size-- and then we will just do minHeapify so that heap becomes correct;
        */
       if(size==0){
        cout<<"No heap bro"<<endl;
       }
       if(size==1){
        size--;
        return arr[0];
       }
       swap(arr[0],arr[size-1]);
       size--;
       MinHeapify(0);
       return arr[size];
    }
      void printHeap(){
        for(int i=0; i<size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};
int main(){
    MinHeap h(10);

    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);

    cout << "Heap elements: ";
    h.printHeap();

    h.insert(1);
    cout << "After inserting 1: ";
    h.printHeap();
    cout << "Extracted min: " << h.extractMin() << endl;
    cout << "Heap after extracting min: ";
    h.printHeap();

    return 0;
}