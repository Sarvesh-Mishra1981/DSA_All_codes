/*
This is the normal version of the question in this this is quite simple 
when the graph is increesing then we will sell it so it simple and just compare the next element
*/
#include<iostream>
#include<vector>
using namespace std;
int pizza(vector<int>& a){
    int mini=a[0];
    int profit=0;
    for(int i=1;i<a.size();i++){
        int diff=a[i]-mini;
        profit=max(profit,diff);
        mini=min(mini,a[i]);
    }
    return profit;
}
int main(){
vector<int> a = {7, 1, 5, 3, 6, 4};

    int maxProfit = pizza(a);
    cout << "Maximum profit possible: " << maxProfit << endl;

    return 0;
}