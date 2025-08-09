#include<iostream>
#include <vector>
using namespace std;
//the idea is if n-1 elements are sorted then the last elemnet is sorted ,
//what we do is that we fix the last element and then sort the n-1 elements hence we get the full sorted 
//time complexiyt is 0(n^2)
void bublesort(vector<int>& a){
    int n=a.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
           if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
           }
        }
    }
}
int main(){
    vector<int> a={3,4,6,9,2,1};
    bublesort(a);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<' ';
    }
}