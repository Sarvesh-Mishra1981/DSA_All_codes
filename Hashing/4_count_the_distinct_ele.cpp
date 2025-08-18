//the problem is to count the distict element in the array so we use the idea of the set where no elemnt is repaeted
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int countthedigits(vector<int>& a){
    unordered_set<int> m(a.begin(),a.end());
    return m.size();
}
int main(){
    vector<int> a={1,2,3,4,4,4,5};
    cout<<countthedigits(a);
    return 0;
}
