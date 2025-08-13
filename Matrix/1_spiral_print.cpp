#include<iostream>
#include<vector>
using namespace std;
void print_spiral(vector<vector<int>>& a){
    int n=a.size();
    int m=a[0].size();
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<m;j++){
                cout<<a[i][j]<<' ';
            }
        }
        else{
            for(int j=m-1;j>=0;j--){
                cout<<a[i][j]<<' ';
            }
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    print_spiral(matrix);
    return 0;

}