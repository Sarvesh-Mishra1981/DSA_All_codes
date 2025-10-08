/*
Simailar to last q and here what we will do is that we will make the weight as constraint and next 
we wll sort on the basis of the dividing wt and the cost
*/
#include<iostream>
#include<vector>
using namespace std;
bool Mycmp(pair<int,int>& a,pair<int,int>& b){
    int x=floor(a.first/a.second);
    int y=floor(b.first/b.second);
    return x>y;
}
double Fractional_Knapsack(vector<pair<int,int>>& a,int k){
    sort(a.begin(),a.end(),Mycmp);
    double res;
    for(int i=0;i<a.size();i++){
        if(a[i].second<=k){
            res+=a[i].first;
            k-=a[i].second;
        }
        else {
            res+=a[i].first*(floor(k/(a[i].second)));
            break;
        }
    }
    return res;
}
int main(){
     vector<pair<int, int>> items = {
        {60, 10}, {100, 20}, {120, 30}
    };
    int capacity = 50;

    double maxValue = Fractional_Knapsack(items, capacity);

    cout << "Maximum value we can obtain = " << maxValue << endl;
    return 0;
}