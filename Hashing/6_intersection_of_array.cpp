#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void intersection(vector<int>& a,vector<int>& b){
    unordered_set<int> m(a.begin(),a.end());
    for(int i=0;i<b.size();i++){
        if(m.find(b[i])!=m.end()){
            cout<<b[i]<<" ";
        }
    }
}

int main(){
    vector<int> a={1,2,3,4,5};
    vector<int> b={3,4,5};
    intersection(a,b);
    return 0;
}

