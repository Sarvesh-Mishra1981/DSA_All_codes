/*
This can be code to solve the pathway of the ret in the maze;
and u can go either down orr right
*/
#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<vector<int>>& a,int i,int j){
    return (i<a.size() && j<a[0].size() && a[i][j]==1);
}
bool SolveMazeRec(vector<vector<int>>& a,vector<vector<int>>& result,int i,int j){
    int x=a.size();int y=a[0].size();
    if(i==x-1 && j==y-1) {
        result[i][j]=1;
        return true;
    }
    if(isSafe(a,i,j)){
        result[i][j]=1;
        if(SolveMazeRec(a,result,i+1,j)) return true;
        else if(SolveMazeRec(a,result,i,j+1)) return true;
        result[i][j]=0;
    }
    return false;
}
bool Solvemaze(vector<vector<int>>& a){
    int n=a.size();
    int m=a[0].size();
    vector<vector<int>> result(n,vector<int>(m,0));
   if (!SolveMazeRec(a, result, 0, 0)) {
        cout << "No path found!" << endl;
        return false;
    } else {
        cout << "Path matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        return true;
}
}
int main(){
vector<vector<int>> maze1 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    cout << "Test Case 1:" << endl;
    Solvemaze(maze1);
    cout << endl;

    vector<vector<int>> maze2 = {
        {1, 0, 0},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << "Test Case 2:" << endl;
    Solvemaze(maze2);
    cout << endl;

    vector<vector<int>> maze3 = {
        {1, 0},
        {0, 1}
    };

    cout << "Test Case 3:" << endl;
    Solvemaze(maze3);
}