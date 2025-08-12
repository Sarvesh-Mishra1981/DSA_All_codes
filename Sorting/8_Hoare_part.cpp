#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int hpartition(vector<int>& a,int l,int h){
    int pivot=a[l];
    int i=l-1;
    int j=h+1;
    while(true){
        do{i++;} while(a[i]<pivot);
       do{j--;} while(a[i]>pivot);
       if(i>=j) return j;
       swap(a[i],a[j]);

    }
}
void qSort(vector<int>& a,int l,int h){
    if(l<h){
        int p=hpartition(a,l,h);
        qSort(a,l,p);
        qSort(a,p+1,h);
    }
}

int main(){
    vector<int> a={3,4,6,9,2,1};
    qSort(a,0,a.size()-1);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<' ';
    }
}
//quick sort is best in terms of the fast but the  in terms of the stability it is megre sort
//in place,tail recursive 
//worst -O(n^2) in v=best case-when everything sorted then  O(nlogn ) and the space complexity is O(n)