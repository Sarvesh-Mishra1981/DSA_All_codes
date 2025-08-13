#include<iostream>
#include<vector>
using namespace std;
void spiral(vector<vector<int>>& a){
    int n=a.size();
    int m=a[0].size();
    int top=0,bottom=n-1,left=0,right=m-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            cout<<a[top][i]<<' ';
        }
        top++;
        for(int i=top;i<=bottom;i++){
            cout<<a[i][right]<<' ';
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
            cout<<a[bottom][i]<<' ';
        }
        }
        bottom--;
        if(left<=right){
             for(int i=bottom;i>=top;i--){
            cout<<a[i][left]<<' ';
        }
        left++;
        }
    }
    }


int main(){
    vector<vector<int>> a= {{1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
       spiral(a);
    return 0;
}