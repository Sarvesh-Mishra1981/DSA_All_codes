#include<iostream>
#include<vector>
using namespace std;
void getTheNum(vector<vector<int>>& a,int target){
    int n=a.size();
    int m=a[0].size();
    int i=0;
    int j=n-1;
    while(i<n && j>=0){
        if(target==a[i][j]) {cout<<i<<','<<j; return ;}
        else if(target>a[i][j]) i++;
        else j--;
    }
}

int main(){
    vector<vector<int>> a= {{1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
        getTheNum(a,5);
    return 0;
}