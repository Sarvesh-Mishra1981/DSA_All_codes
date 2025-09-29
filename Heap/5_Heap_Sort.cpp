#include<iostream>
#include<algorithm>
using namespace std;
void Heapify(vector<int>& a,int n,int i){
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<n && a[largest]<a[left]) largest=left;
    if(right<n && a[largest]<a[right]) largest=right;
    if(largest!=i){
        swap(a[largest],a[i]);
        Heapify(a,n,largest);
    }
}
void buildHeap(vector<int>& a,int n){
    for(int i=(n/2)-1;i>=0;i++){
        Heapify(a,n,i);
    }
}
void HeapSort(vector<int>& a,int n){
    buildHeap(a,n);
    for(int i=n-1;i>=0;i++){
        swap(a[0],a[i]);
        Heapify(a,i,0);
    }
}
void printarray(vector<int>& a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    vector<int> a{12, 11, 13, 5, 6, 7};
    HeapSort(a,a.size());
    printarray(a,a.size());
}