/*
in this problem we need to find the activity such that we can perform the max number of the activity 
so we here use the idea of the greedy algo.

*/
#include<iostream>
#include<vector>
using namespace std;
bool Mycmp(pair<int,int>& a,pair<int,int>& b){
    return b.second>a.second;//if this return false then it will chnage 
}
vector<pair<int,int>> Activity_selector(vector<pair<int,int>>& a){
    //first we will sort it on the basis of the ending time;
    sort(a.begin(),a.end(),Mycmp);
    vector<pair<int,int>> res;
    int prev=0;
    res.push_back(a[prev]);
    int n=a.size();
    for(int i=1;i<n;i++){
        if(a[i].first>=a[prev].second){
            res.push_back(a[i]);
            prev=i;
        }
    }
    return res;
}
int main(){
 vector<pair<int, int>> a = {{1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}};
    vector<pair<int, int>> result = Activity_selector(a);

    cout << "Selected activities:\n";
    for (auto& p : result) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    cout << "Maximum number of activities: " << result.size() << endl;

    return 0;

}