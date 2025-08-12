#include<iostream>
#include<vector>
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
int FindK(vector<int>& a,int k){
    int low=0;
    int high=a.size()-1;
    while(low<high){
        int p=lpartition(a,low,high);
        if(p==k) return a[p];
        else if(p>k) high=p-1;
        else low=p+1;
    }

return -1;
}
int main(){
    vector<int> a={3,4,6,9,2,1};
    cout<<FindK(a,2);
    return 0;
}