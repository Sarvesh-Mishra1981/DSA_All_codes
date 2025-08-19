#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
bool isPairsum(vector<int>& a,int sum){
    unordered_set<int> m;
    for(int i=0;i<a.size();i++){
        if(m.find(sum-a[i])!=m.end()){
            return true;
        }
        else{
            m.insert(a[i]);
        }
    }
    return false;
}
int main(){
    vector<int> a={1,2,3,4,5,6,6};
    cout<<isPairsum(a,3);
    return 0;
}