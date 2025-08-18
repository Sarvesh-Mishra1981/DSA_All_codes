//the problem is to count the freq of the element in the array so we use the idea of the umap 
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
void freqthedigits(vector<int>& a){
    unordered_map<int,int> m;
    for(int i=0;i<a.size();i++){
        m[a[i]]++;
    }
    for(auto& p:m){
        cout<<p.first<<"->"<<p.second<<endl;
    }
}
int main(){
    vector<int> a={1,2,3,4,4,4,5};
    freqthedigits(a);
    return 0;
}
