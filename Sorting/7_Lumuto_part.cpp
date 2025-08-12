#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lpartition(vector<int>& a,int l,int h){
    int pivot=a[h];
    int k=l-1;
    for(int i=l;i<=h-1;i++){
        if(a[i]<pivot){
            k++;
            swap(a[i],a[k]);
        }
    }
    swap(a[k+1],a[h]);
    return k+1;
}
void qSort(vector<int>& a,int l,int h){
    if(l<h){
        int p=lpartition(a,l,h);
        qSort(a,l,p-1);
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