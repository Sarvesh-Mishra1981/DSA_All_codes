#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void more_than_nByk(vector<int>& a,int k){
    int n=a.size();
    unordered_map<int,int> m;
    int tar=n/k;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }
    for(auto& p:m){
        if(p.second>tar){
            cout<<p.first<<" ";
        }
    }

}
int main(){
    vector<int> a={1,2,3,4,4,4,5,6,7};
    more_than_nByk(a,4);
    return 0;
}