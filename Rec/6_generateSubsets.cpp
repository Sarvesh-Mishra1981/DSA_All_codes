#include<iostream>
#include<vector>
using namespace std;
/*
In this we need to generate the subsets and the concept is that either we will include the next term or not
and when the length of that wil be equal to the total length then we will return
*/
void GenerateSubset(vector<int>& a,vector<int>& curr,int i,vector<vector<int>>& ans){
    if(i==a.size()){
        ans.push_back(curr);
        return;
    }
    GenerateSubset(a,curr,i+1,ans);
    curr.push_back(a[i]);
    GenerateSubset(a,curr,i+1,ans);

}
int main(){
 vector<int> a = {1, 2, 3};  
    vector<int> curr;
    vector<vector<int>> ans;

    GenerateSubset(a, curr, 0, ans);

    cout << "All subsets:\n";
    for (auto& subset : ans) {
        cout << "{ ";
        for (int num : subset) cout << num << " ";
        cout << "}\n";
    }

    return 0;
}