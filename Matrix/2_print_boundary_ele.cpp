#include<iostream>
#include<vector>
using namespace std;
void print_boundary(vector<vector<int>>& a){
    int n=a.size();
    int  m=a[0].size();
    if(n==1){
        for(int i=0;i<m;i++){
            cout<<a[0][i]<<' ';
        }
    }
    else if(m==1){
        for(int i=0;i<n;i++){
            cout<<a[i][0]<<' ';
        }
    }
    else{
        for(int i=0;i<m;i++){
            cout<<a[0][i]<<' ';
        }
        for(int i=1;i<n;i++){
            cout<<a[i][m-1]<<' ';
        }
        for(int i=m-2;i>=0;i--){
            cout<<a[n-1][i]<<' ';
        }
        for(int i=n-2;i>=0;i--){
            cout<<a[i][0]<<' ';
        }
    }
}

int main(){
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    print_boundary(matrix);
    return 0;
    return 0;
}