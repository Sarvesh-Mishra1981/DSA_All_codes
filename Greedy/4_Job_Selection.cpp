/*
In this we have the rules---:
1. we have the job and its deadline and each job take 1 unit of time
2. you have to respect the deadline and then tell the max profit u can make;


the bsic idea is that we will make the array and we will push the val till that a[i] of deadline will
not get fulled.
*/
#include<vector>
#include<iostream>
using namespace std;
bool Mycmp(pair<int,int>& a,pair<int,int>& b){
    return a.second>b.second;
}
int Job_selection(vector<pair<int,int>>& a){
    sort(a.begin(),a.end(),Mycmp);
    int res=0;
    for(int i=0;i<a.size();i++){
        res=max(res,a[i].second);
    }
    vector<int> deadline(res,-1);
    int ans=0;
    int count=1;
    for(int i=0;i<a.size();i++){
        if(deadline[a[i].first]==-1){
            ans+=a[i].second;
            deadline[count]=a[i].second;
            count++;
        }
    }
    return ans;
}
int main(){
vector<pair<int, int>> jobs = {
        {4, 70},
        {1, 80},
        {1, 30},
        {1, 100}
    };
     vector<pair<int, int>> jobs2 = {
        {2, 50}, {2, 60}, {3, 20}, {3, 30}
    };

    int maxProfit = Job_selection(jobs2);
    cout << "Maximum profit = " << maxProfit << endl;

    return 0;

}