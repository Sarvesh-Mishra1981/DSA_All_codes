#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void distinct_ele(vector<int>& a,int k){
    int n=a.size();
    unordered_map<int,int> m;
    vector<vector<int>> s;
    for(int i=0;i<k;i++){
        m[a[i]]++;
    }
    cout<<m.size()<<endl;
    for(int i=k;i<n;i++){
        m[a[i-k]]--;
        if(m[a[i-k]]==0) m.erase(a[i-k]);
        m[a[i]]++;
        cout<<m.size()<<endl;
    }
}
int main(){
    vector<int> a={1,2,3,3,4,4,4,5,5,5,6,6,7,7,8,9};
    distinct_ele(a,3);
    return 0;
}