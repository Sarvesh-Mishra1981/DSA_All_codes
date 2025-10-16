/*
In this we need to find the permutation and the idea is we will do backtracking and 
we will swap and the permute and then we will do backtracking
*/
#include<iostream>
#include<vector>
using namespace std;
void Permute(vector<int>& a,int i,vector<vector<int>>& ans){
    if(i==a.size()){
        ans.push_back(a);
        return;
    }
    for(int j=i;j<a.size();j++){
        swap(a[i],a[j]);
        Permute(a,i+1,ans);
        swap(a[i],a[j]);
    }
}
int main(){
  vector<int> a = {1, 2, 3};  
    vector<vector<int>> ans;

    Permute(a, 0, ans);

    cout << "All permutations:\n";
    for (auto& perm : ans) {
        cout << "{ ";
        for (int num : perm) cout << num << " ";
        cout << "}\n";
    }

    return 0;
}