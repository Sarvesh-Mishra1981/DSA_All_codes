#include<iostream>
#include<vector>
using namespace std;
void transpose(vector<vector<int>>& a){
    int n=a.size();
    int m=a[0].size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            swap(a[i][j],a[j][i]);
        }
    }
}
void rotate_by_90(vector<vector<int>>& a){
    transpose(a);
    int n=a.size();
    int m=a[0].size();
    int low=0;
    int high=n-1;
    while(low<=high){
        for(int i=0;i<m;i++){
            swap(a[low][i],a[high][i]);
        }
    }
}
int main(){
     vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotate_by_90(matrix);
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;

}