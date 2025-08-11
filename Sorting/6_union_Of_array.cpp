#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>
using namespace std;

void Intersection(vector<int>& a, vector<int>& b) {
    unordered_set<int> x(a.begin(),a.end());
    for(int i=0;i<b.size();i++){
        x.insert(b[i]);
    }
    for(auto& p:x){
        cout<<p<<" ";
    }
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 6};
    Intersection(a, b);
    return 0;
}
